# Digital Forensics & Security Log Analyzer

## 📌 Project Overview

The **Digital Forensics & Security Log Analyzer** is a C++ cybersecurity project that analyzes system log entries to identify suspicious activities and potential security threats. It detects failed login attempts, unauthorized access, malware indicators, privilege escalation, ransomware indicators, data exfiltration, and possible brute-force activity.

The tool generates a detailed forensic report containing event categories, severity levels, IP addresses, risk scores, and recommended actions.

## 🚀 Features

- **Log Analysis:** Reads log entries from `forensic_log.txt`.
- **Sample Data:** Uses built-in sample logs if the input file is unavailable.
- **Threat Detection:** Identifies suspicious activities and potential security threats.
- **Severity Classification:** Categorizes detected events as LOW, MEDIUM, HIGH, or CRITICAL.
- **IP Address Extraction:** Extracts basic IPv4 address patterns from log entries.
- **Brute-Force Detection:** Flags repeated failed login attempts from the same detected IP address.
- **Risk Scoring:** Assigns rule-based risk points to detected events.
- **Security Recommendations:** Provides suggested actions for investigating suspicious activities.
- **Automated Reporting:** Saves analysis results to `forensic_report.txt`.
- **Event Statistics:** Displays a summary of detected security indicators.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **File Handling:** `ifstream` and `ofstream`
- **Data Structures:** Vectors, maps, and structures
- **Libraries:** `iostream`, `fstream`, `string`, `vector`, `map`, `cctype`, `ctime`, and `cstdlib`
- **Development Environment:** VS Code / Dev-C++

## 📂 Project Structure

```text
Digital-Forensics-Analyzer/
│
├── digital_forensics.cpp
├── forensic_log.txt
├── forensic_report.txt
└── README.md
```

`forensic_log.txt` is the input file and is optional. If it is missing, the program uses built-in sample logs.

`forensic_report.txt` is automatically generated when the analysis finishes.

## ⚙️ How to Run

### 1. Clone the Repository

```bash
git clone YOUR_REPOSITORY_URL
cd Digital-Forensics-Analyzer
```

Replace `YOUR_REPOSITORY_URL` with your GitHub repository URL.

### 2. Compile the Program

Make sure a C++ compiler such as GCC is installed.

```bash
g++ digital_forensics.cpp -o digital_forensics
```

### 3. Run the Program

**Windows PowerShell:**

```powershell
.\digital_forensics.exe
```

**Linux / macOS / Git Bash:**

```bash
./digital_forensics
```

### 4. Provide Input Logs

Create a file named `forensic_log.txt` in the program's working directory and add entries such as:

```text
10:20 Login successful - User: admin - IP: 192.168.1.10
10:25 Failed login - User: unknown - IP: 203.0.113.15
10:26 Failed login - User: unknown - IP: 203.0.113.15
10:27 Failed login - User: unknown - IP: 203.0.113.15
10:30 Suspicious connection - IP: 198.51.100.8
10:35 Unauthorized access attempt - IP: 198.51.100.8
10:45 Malware detected on workstation
11:00 Privilege escalation detected - User: guest
11:05 Ransomware indicator detected
11:10 Data exfiltration alert
```

## 📊 Analysis and Reporting

The program displays a summary containing:

- Total log entries
- Suspicious events
- Failed login attempts
- Possible brute-force sources
- Unauthorized access events
- Malware indicators
- Attack indicators
- Privilege escalation events
- Critical-category events
- Data exfiltration indicators
- Aggregate risk score

The detailed report includes the original log entry, detected category, severity, extracted IP address, risk points, recommended action, and failed-login counts by IP.

## 🔍 Detection Categories

| Category | Purpose |
|---|---|
| Failed Login | Identifies unsuccessful login attempts |
| Suspicious Activity | Flags suspicious or unauthorized events |
| Malware Indicators | Detects malware-related keywords |
| Attack Indicators | Identifies attack-related log messages |
| Privilege Escalation | Flags potential privilege misuse |
| Ransomware Indicators | Identifies ransomware-related alerts |
| Data Exfiltration | Flags possible unauthorized data transfers |
| Possible Brute-Force Activity | Identifies repeated failed logins from one IP |

## 🎯 Learning Outcomes

- Understanding digital forensics and security log analysis
- Applying C++ file handling to cybersecurity tasks
- Using strings and pattern matching for threat identification
- Working with vectors, maps, and structures
- Implementing basic rule-based threat classification
- Generating automated security reports
- Understanding risk scoring and incident investigation

## ⚠️ Limitations

This project uses predefined keyword-based detection rules and is intended for educational purposes. Its findings are security indicators, not proof of a confirmed attack. IP extraction and risk scoring are basic implementations and require further validation before real-world use.

## 🔮 Future Enhancements

- Interactive command-line menu
- More robust IP address validation
- Date and time filtering
- Export reports to CSV or JSON
- Improved brute-force detection with configurable thresholds
- Graphical dashboard for event statistics
- Integration with real system logs
- More advanced correlation between events

## 👩‍💻 Author

**Sanjana Mallick**

B.Tech Computer Science and Information Technology  
Specialization: Cybersecurity

## 📜 License

This project is intended for educational and cybersecurity learning purposes. Add an open-source license if you want others to reuse or modify the code under defined terms.
security log analysis**.
