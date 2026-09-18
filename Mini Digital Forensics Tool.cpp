#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string line;
    string lowerLine;

    int totalEntries = 0;
    int failedLogin = 0;
    int suspicious = 0;
    int unauthorized = 0;
    int malware = 0;
    int attack = 0;
    int suspiciousEvents = 0;

    /* Sample forensic log data */
    string logs[] =
    {
        "10:20 Login successful - User: admin",
        "10:25 Failed login attempt - User: unknown",
        "10:27 Failed login attempt - User: unknown",
        "10:30 Suspicious connection detected",
        "10:35 Unauthorized access attempt",
        "10:40 Login successful - User: sanjana",
        "10:45 Malware detected in system",
        "10:50 Normal system activity",
        "10:55 Attack detected from unknown source",
        "11:00 Login successful - User: admin"
    };

    int totalLogs = 10;

    ofstream reportFile;
    reportFile.open("forensic_report.txt");

    cout << "==========================================" << endl;
    cout << "       MINI DIGITAL FORENSICS TOOL        " << endl;
    cout << "==========================================" << endl;
    cout << endl;

    cout << "Analyzing forensic logs..." << endl;
    cout << endl;

    reportFile << "==========================================" << endl;
    reportFile << "       DIGITAL FORENSICS REPORT           " << endl;
    reportFile << "==========================================" << endl;
    reportFile << endl;

    reportFile << "Suspicious Log Entries:" << endl;
    reportFile << "------------------------------------------" << endl;

    for (int i = 0; i < totalLogs; i++)
    {
        line = logs[i];
        totalEntries++;

        lowerLine = line;

        /* Convert text to lowercase */
        for (unsigned int j = 0; j < lowerLine.length(); j++)
        {
            lowerLine[j] = tolower(lowerLine[j]);
        }

        bool isSuspicious = false;

        if (lowerLine.find("failed login") != string::npos)
        {
            failedLogin++;
            isSuspicious = true;
        }

        if (lowerLine.find("suspicious") != string::npos)
        {
            suspicious++;
            isSuspicious = true;
        }

        if (lowerLine.find("unauthorized") != string::npos)
        {
            unauthorized++;
            isSuspicious = true;
        }

        if (lowerLine.find("malware") != string::npos)
        {
            malware++;
            isSuspicious = true;
        }

        if (lowerLine.find("attack") != string::npos)
        {
            attack++;
            isSuspicious = true;
        }

        if (isSuspicious)
        {
            suspiciousEvents++;
            reportFile << line << endl;
        }
    }

    cout << "---------- ANALYSIS RESULTS ----------" << endl;
    cout << endl;

    cout << "Total Log Entries       : " << totalEntries << endl;
    cout << "Suspicious Events       : " << suspiciousEvents << endl;
    cout << "Failed Login Attempts   : " << failedLogin << endl;
    cout << "Suspicious Activities   : " << suspicious << endl;
    cout << "Unauthorized Access     : " << unauthorized << endl;
    cout << "Malware Events          : " << malware << endl;
    cout << "Attack Events           : " << attack << endl;

    reportFile << endl;
    reportFile << "---------- SUMMARY ----------" << endl;
    reportFile << endl;

    reportFile << "Total Log Entries       : " << totalEntries << endl;
    reportFile << "Suspicious Events       : " << suspiciousEvents << endl;
    reportFile << "Failed Login Attempts   : " << failedLogin << endl;
    reportFile << "Suspicious Activities   : " << suspicious << endl;
    reportFile << "Unauthorized Access     : " << unauthorized << endl;
    reportFile << "Malware Events          : " << malware << endl;
    reportFile << "Attack Events           : " << attack << endl;

    reportFile << endl;
    reportFile << "==========================================" << endl;
    reportFile << "       END OF FORENSICS REPORT            " << endl;
    reportFile << "==========================================" << endl;

    reportFile.close();

    cout << endl;
    cout << "Analysis completed successfully!" << endl;
    cout << "Report saved as forensic_report.txt" << endl;

    cout << endl;
    cout << "Press any key to exit..." << endl;

    cin.get();

    return 0;
}
