# 🔍 Mini Digital Forensics Tool

## 📌 Overview

**Mini Digital Forensics Tool** is a beginner-friendly cybersecurity project developed using **C++**. The tool analyzes text-based forensic log files to identify and summarize potentially suspicious activities.

It searches the log file for predefined security-related keywords such as **failed login attempts, unauthorized access, suspicious activity, malware, and attacks**. The tool counts these events, displays the suspicious log entries, and generates a basic forensic investigation report.

This project demonstrates the practical application of **C++ file handling, string processing, log analysis, and fundamental digital forensics concepts**.

---

## 🎯 Objectives

* Analyze forensic log files automatically.
* Identify potentially suspicious activities.
* Count different types of security events.
* Display relevant suspicious log entries.
* Generate a basic forensic investigation report.
* Understand how log analysis can support digital investigations.

---

## ✨ Features

* 📂 Read data from a forensic log file.
* 🔎 Search for predefined security keywords.
* 📊 Count suspicious events.
* 🚨 Detect failed login attempts.
* 🔐 Identify unauthorized access attempts.
* ⚠️ Detect suspicious activities.
* 🦠 Search for malware-related entries.
* 💥 Search for attack-related entries.
* 📄 Generate a forensic report.
* 💻 Simple console-based interface.

---

## 🛠️ Technologies Used

* **Programming Language:** C++
* **IDE:** Dev-C++ / Visual Studio Code
* **Concepts:**

  * File Handling
  * Strings
  * Loops
  * Conditional Statements
  * Functions
  * Log Analysis

---

## 📁 Project Structure

```text
Mini-Digital-Forensics-Tool/
│
├── main.cpp
├── forensic_log.txt
├── forensic_report.txt
└── README.md
```

---

## ⚙️ How It Works

The tool follows these basic steps:

```text
Forensic Log File
       ↓
Read Log Entries
       ↓
Search Security Keywords
       ↓
Identify Suspicious Entries
       ↓
Count Security Events
       ↓
Generate Forensic Report
```

---

## 🚀 How to Run

### 1. Clone the repository

```bash
git clone https://github.com/your-username/Mini-Digital-Forensics-Tool.git
```

### 2. Open the project

Open `main.cpp` using **Dev-C++**, **Visual Studio Code**, or another C++ IDE.

### 3. Add the log file

Make sure `forensic_log.txt` is present in the same folder as the executable.

### 4. Compile the program

Compile and run `main.cpp`.

### 5. View the report

After analysis, the program generates:

```text
forensic_report.txt
```

This file contains the summary of detected suspicious activities.

---

## 📝 Sample Log File

Example `forensic_log.txt`:

```text
10:20 Login successful - User: admin
10:25 Failed login attempt - User: unknown
10:27 Failed login attempt - User: unknown
10:30 Suspicious connection detected
10:35 Unauthorized access attempt
10:40 Login successful - User: sanjana
10:45 Malware detected in system
```

---

## 📊 Sample Output

```text
========== DIGITAL FORENSICS REPORT ==========

Total Log Entries: 7

Suspicious Events Found: 5

Failed Login Attempts: 2
Suspicious Events: 1
Unauthorized Events: 1
Malware Events: 1
Attack Events: 0

---------- Suspicious Entries ----------

10:25 Failed login attempt - User: unknown
10:27 Failed login attempt - User: unknown
10:30 Suspicious connection detected
10:35 Unauthorized access attempt
10:45 Malware detected in system

==============================================
```

---

## 🔐 Cybersecurity Concepts

This project provides an introduction to:

* **Digital Forensics**
* **Log Analysis**
* **Security Event Detection**
* **Incident Investigation**
* **Authentication Monitoring**
* **Suspicious Activity Identification**

Log analysis is an important part of cybersecurity investigations because security logs can provide information about events occurring on a system.

---

## ⚠️ Disclaimer

This project is created for **educational and cybersecurity learning purposes**. It performs basic keyword-based analysis of locally provided log files and is not intended to replace professional digital forensic investigation tools.

---

## 🔮 Future Improvements

Possible future enhancements include:

* Add timestamps and date filtering.
* Support CSV and other log formats.
* Add IP address analysis.
* Detect repeated login attempts from the same IP.
* Add severity levels such as Low, Medium, and High.
* Create graphical reports.
* Add file hashing for basic evidence integrity checking.
* Add more advanced log-analysis rules.

---

## 👩‍💻 Author

**Sanjana Mallick**

B.Tech CSIT — Cybersecurity

---

## ⭐ Project Purpose

This project was developed to strengthen practical knowledge of **C++ programming and cybersecurity**, particularly in the area of **digital forensics and security log analysis**.
