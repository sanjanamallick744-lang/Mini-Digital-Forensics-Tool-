
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Event
{
    string log;
    string category;
    string severity;
    string ip;
    string recommendation;
    int risk;
};

string toLowerCase(string text)
{
    for (unsigned int i = 0; i < text.length(); i++)
        text[i] = tolower((unsigned char)text[i]);

    return text;
}

string findIP(string text)
{
    for (unsigned int i = 0; i < text.length(); i++)
    {
        if (!isdigit((unsigned char)text[i]))
            continue;

        unsigned int j = i;

        while (j < text.length() &&
              (isdigit((unsigned char)text[j]) || text[j] == '.'))
            j++;

        string candidate = text.substr(i, j - i);

        int dots = 0, parts = 0;
        bool valid = true;
        unsigned int start = 0;

        for (unsigned int k = 0; k <= candidate.length(); k++)
        {
            if (k == candidate.length() || candidate[k] == '.')
            {
                if (k == start)
                {
                    valid = false;
                    break;
                }

                string part = candidate.substr(start, k - start);

                if (part.length() > 3 || atoi(part.c_str()) > 255)
                    valid = false;

                parts++;
                start = k + 1;
            }

            if (k < candidate.length() && candidate[k] == '.')
                dots++;
        }

        if (valid && dots == 3 && parts == 4)
            return candidate;

        i = j;
    }

    return "Not found";
}

Event analyzeLog(string line)
{
    Event e;
    string text = toLowerCase(line);

    e.log = line;
    e.category = "Normal Activity";
    e.severity = "INFO";
    e.ip = findIP(line);
    e.recommendation = "No immediate action required.";
    e.risk = 0;

    if (text.find("ransomware") != string::npos ||
        text.find("data exfiltration") != string::npos)
    {
        e.category = "Ransomware / Data Exfiltration";
        e.severity = "CRITICAL";
        e.recommendation =
            "Escalate immediately; investigate affected systems.";
        e.risk = 40;
    }
    else if (text.find("privilege escalation") != string::npos ||
             text.find("root access") != string::npos)
    {
        e.category = "Privilege Escalation";
        e.severity = "HIGH";
        e.recommendation =
            "Review account permissions and authentication logs.";
        e.risk = 30;
    }
    else if (text.find("malware") != string::npos ||
             text.find("attack") != string::npos)
    {
        e.category = "Malware / Attack Indicator";
        e.severity = "HIGH";
        e.recommendation =
            "Investigate the source and examine affected systems.";
        e.risk = 25;
    }
    else if (text.find("unauthorized") != string::npos ||
             text.find("suspicious") != string::npos)
    {
        e.category = "Suspicious / Unauthorized Activity";
        e.severity = "MEDIUM";
        e.recommendation =
            "Verify the activity and review access records.";
        e.risk = 15;
    }
    else if (text.find("failed login") != string::npos ||
             text.find("login failed") != string::npos)
    {
        e.category = "Failed Login";
        e.severity = "LOW";
        e.recommendation =
            "Monitor repeated failures and verify the user.";
        e.risk = 5;
    }

    return e;
}

int main()
{
    vector<string> logs;
    vector<Event> events;
    map<string, int> failedByIP;

    string line;
    ifstream inputFile("forensic_log.txt");

    if (inputFile)
    {
        while (getline(inputFile, line))
        {
            if (!line.empty())
                logs.push_back(line);
        }

        inputFile.close();
        cout << "Source: forensic_log.txt" << endl;
    }
    else
    {
        logs.push_back("10:20 Login successful - User: admin - IP: 192.168.1.10");
        logs.push_back("10:25 Failed login - User: unknown - IP: 203.0.113.15");
        logs.push_back("10:26 Failed login - User: unknown - IP: 203.0.113.15");
        logs.push_back("10:27 Failed login - User: unknown - IP: 203.0.113.15");
        logs.push_back("10:30 Suspicious connection - IP: 198.51.100.8");
        logs.push_back("10:35 Unauthorized access attempt - IP: 198.51.100.8");
        logs.push_back("10:40 Login successful - User: sanjana - IP: 192.168.1.12");
        logs.push_back("10:45 Malware detected on workstation");
        logs.push_back("10:50 Normal system activity");
        logs.push_back("10:55 Attack detected from unknown source");
        logs.push_back("11:00 Privilege escalation detected - User: guest");
        logs.push_back("11:05 Ransomware indicator detected");
        logs.push_back("11:10 Data exfiltration alert");

        cout << "Source: Built-in sample logs" << endl;
    }

    ofstream reportFile("forensic_report.txt");

    if (!reportFile)
    {
        cout << "Error: Cannot create forensic_report.txt" << endl;
        return 1;
    }

    int failed = 0, suspicious = 0, unauthorized = 0;
    int malware = 0, attacks = 0, critical = 0;
    int bruteForce = 0, privilege = 0, exfiltration = 0;
    int totalRisk = 0;

    for (unsigned int i = 0; i < logs.size(); i++)
    {
        Event e = analyzeLog(logs[i]);

        if (e.category == "Failed Login")
        {
            failed++;

            if (e.ip != "Not found")
                failedByIP[e.ip]++;
        }

        if (e.category == "Suspicious / Unauthorized Activity")
            suspicious++;

        if (toLowerCase(logs[i]).find("unauthorized") != string::npos)
            unauthorized++;

        if (toLowerCase(logs[i]).find("malware") != string::npos ||
            toLowerCase(logs[i]).find("ransomware") != string::npos)
            malware++;

        if (toLowerCase(logs[i]).find("attack") != string::npos)
            attacks++;

        if (e.category == "Privilege Escalation")
            privilege++;

        if (e.category == "Ransomware / Data Exfiltration")
        {
            critical++;

            if (toLowerCase(logs[i]).find("data exfiltration") != string::npos)
                exfiltration++;
        }

        totalRisk += e.risk;
        events.push_back(e);
    }

    // Detect repeated failed logins from the same IP.
    for (map<string, int>::iterator it = failedByIP.begin();
         it != failedByIP.end(); ++it)
    {
        if (it->second >= 3)
        {
            bruteForce++;

            Event e;
            e.log = "Repeated failed logins from " + it->first +
                    " (" + to_string(it->second) + " attempts)";
            e.category = "Possible Brute-Force Activity";
            e.severity = "HIGH";
            e.ip = it->first;
            e.recommendation =
                "Verify the source, review authentication records, "
                "and apply appropriate account protections.";
            e.risk = 30;

            events.push_back(e);
            totalRisk += e.risk;
        }
    }

    time_t now = time(0);
    char *timeText = ctime(&now);
    string timestamp = timeText ? timeText : "Unknown";

    int suspiciousCount = 0;
    for (unsigned int i = 0; i < events.size(); i++)
    {
        if (events[i].risk > 0)
            suspiciousCount++;
    }

    cout << "\n========================================\n";
    cout << "     DIGITAL FORENSICS ANALYZER\n";
    cout << "========================================\n";
    cout << "Report time: " << timestamp;
    cout << "Total log entries: " << logs.size() << endl;
    cout << "Suspicious events: " << suspiciousCount << endl;
    cout << "Failed logins: " << failed << endl;
    cout << "Possible brute-force sources: " << bruteForce << endl;
    cout << "Unauthorized events: " << unauthorized << endl;
    cout << "Malware indicators: " << malware << endl;
    cout << "Attack indicators: " << attacks << endl;
    cout << "Privilege escalation: " << privilege << endl;
    cout << "Critical-category events: " << critical << endl;
    cout << "Data exfiltration indicators: " << exfiltration << endl;
    cout << "Aggregate risk score: " << totalRisk << endl;

    reportFile << "========================================\n";
    reportFile << "       DIGITAL FORENSICS REPORT\n";
    reportFile << "========================================\n";
    reportFile << "Generated: " << timestamp;
    reportFile << "Total log entries: " << logs.size() << endl;
    reportFile << "Suspicious events: " << suspiciousCount << endl;
    reportFile << "Failed logins: " << failed << endl;
    reportFile << "Possible brute-force sources: " << bruteForce << endl;
    reportFile << "Unauthorized events: " << unauthorized << endl;
    reportFile << "Malware indicators: " << malware << endl;
    reportFile << "Attack indicators: " << attacks << endl;
    reportFile << "Privilege escalation: " << privilege << endl;
    reportFile << "Critical-category events: " << critical << endl;
    reportFile << "Data exfiltration indicators: " << exfiltration << endl;
    reportFile << "Aggregate risk score: " << totalRisk << endl;

    reportFile << "\n========== EVENT DETAILS ==========\n";

    for (unsigned int i = 0; i < events.size(); i++)
    {
        if (events[i].risk == 0)
            continue;

        reportFile << "\nEvent: " << events[i].log << endl;
        reportFile << "Category: " << events[i].category << endl;
        reportFile << "Severity: " << events[i].severity << endl;
        reportFile << "IP Address: " << events[i].ip << endl;
        reportFile << "Risk Points: " << events[i].risk << endl;
        reportFile << "Recommendation: "
                   << events[i].recommendation << endl;
    }

    reportFile << "\n========== FAILED LOGIN SOURCES ==========\n";

    for (map<string, int>::iterator it = failedByIP.begin();
         it != failedByIP.end(); ++it)
    {
        reportFile << it->first << " : " << it->second
                   << " failed login attempts";

        if (it->second >= 3)
            reportFile << " - REVIEW REQUIRED";

        reportFile << endl;
    }

    reportFile << "\nNote: These are rule-based indicators, not proof "
               << "of a confirmed attack.\n";
    reportFile << "========================================\n";
    reportFile << "             END OF REPORT\n";
    reportFile << "========================================\n";

    reportFile.close();

    cout << "\nReport saved to forensic_report.txt" << endl;
    cout << "Analysis completed successfully." << endl;

    return 0;
}
