# 🎓 Student-DBMS — `dbase` Utility v2.0

> **Upgraded from a mini project to a real Linux CLI utility!**

A **bare-metal C Linux utility** that works just like `ls`, `cp`, and `cat` — installed into `/sbin` as `dbase`. Manages student records through a **menu-driven terminal interface** with **ANSI color UI**, **linked list** data structures, and **root-protected persistent storage** at `~/.dbase/student.dat`.

---

## 🆕 What's New in v2.0

| Feature | v1.0 | v2.0 |
|---|---|---|
| Executable name | `./exe` | `dbase` (system-wide command) |
| Install location | project folder | `/sbin/dbase` (like `ls`, `cp`) |
| Data file location | `student.dat` (local) | `~/.dbase/student.dat` |
| Delete protection | ❌ None | ✅ Root permission required |
| CLI arguments | ❌ None | ✅ `--help`, `--purge` |
| Directory auto-create | ❌ Manual | ✅ Auto on first run |
| Build & install | `make` only | `make` + `sudo make install` |

---

## 📁 Project Structure

```
Student-DBMS/
│
├── main.c                 # Entry point – CLI args + interactive menu
├── header.h               # Shared typedefs, structs & extern declarations
├── db_utils.c             # get_db_path() and init_db_dir() helpers  ← NEW
│
├── add_new_record.c       # Add a new student record
├── show_the_list.c        # Display all student records
├── count.c                # Count total number of records
│
├── search_name.c          # Search student by name
├── search_rollno.c        # Search student by roll number
├── search_percentage.c    # Search student by percentage
│
├── delete_record_name.c   # Delete a record by student name
├── delete_record_rollno.c # Delete a record by roll number
├── delete_all.c           # Delete all records
│
├── name_sorting.c         # Sort records alphabetically by name
├── rollno_sorting.c       # Sort records by roll number
├── percentage_sorting.c   # Sort records by percentage
├── reverse_list.c         # Reverse the current list order
│
├── save.c                 # Save records → ~/.dbase/student.dat
├── read_data_file.c       # Load records ← ~/.dbase/student.dat
├── print_slow.c           # Animated ANSI text printing utility
│
└── makefile               # Build + install + uninstall automation
```

---

## 🗺️ System Architecture

```
  /sbin/dbase                 ← Installed binary (root:root 755)
       │
       │   runs as any user
       ▼
  ~/.dbase/
       └── student.dat        ← Data file (root:user 440)
                                  ✅ User can READ
                                  ❌ User CANNOT delete (needs sudo)
```

---

## ✨ Features

- **Add Records** — Input student name, roll number, and percentage
- **Display Records** — View all stored records in a formatted ANSI-colored list
- **Search** — Find students by name, roll number, or percentage
- **Delete** — Remove individual records or clear all with confirmation
- **Sort** — Organize by name, roll number, or percentage
- **Reverse** — Reverse the current list order
- **Persistent Storage** — Auto-loads from and saves to `~/.dbase/student.dat`
- **Root-Protected Data** — Data file locked with `chmod 440` after save
- **CLI Mode** — `--help` and `--purge` argument support
- **Auto Directory Init** — Creates `~/.dbase/` on first run automatically
- **ANSI Color UI** — Color-coded menus, prompts, and error messages
- **Input Validation** — 3-strike system with graceful exit

---

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| **C Language** | Core programming language |
| **Singly Linked List** | Dynamic in-memory record management |
| **File I/O** | Persistent storage at `~/.dbase/student.dat` |
| **ANSI Escape Codes** | Color-coded terminal UI |
| **Linux syscalls** | `mkdir`, `chmod`, `chown`, `getuid`, `getenv` |
| **Makefile** | Build, install, and uninstall automation |
| **GCC** | Compilation with `-Wall -Wextra` |

---

## 🚀 Getting Started

### Prerequisites

```bash
sudo apt install gcc make      # Debian / Ubuntu
sudo dnf install gcc make      # Fedora / RHEL
```

### Build

```bash
git clone https://github.com/Ruby-Shankar-V/student-database/.git
cd Student-DBMS
make
```

Expected output:
```
Build successful → ./dbase
Run 'sudo make install' to install to /sbin/dbase
```

### Install to `/sbin` (system-wide)

```bash
sudo make install
```

Verify:
```bash
which dbase
# /sbin/dbase

ls -l /sbin/dbase
# -rwxr-xr-x 1 root root ... /sbin/dbase
```

Now `dbase` works from **any directory**, for **any user**:
```bash
dbase
dbase --help
sudo dbase --purge
```

---

## 💻 CLI Usage

```bash
dbase                  # Launch interactive menu
dbase --help           # Show usage info
sudo dbase --purge     # Delete the saved database (root only)
sudo make uninstall    # Remove dbase from /sbin
```

### `--help` output
```
Usage: dbase [OPTION]

  (no option)      Launch interactive menu
  --help           Show this help message
  --purge          Delete the saved database (root only)

Data file  : ~/.dbase/student.dat
Binary     : /sbin/dbase
```

---

## 📋 Interactive Menu

```
+++++++++++++++++++++++++++++++++++++++++++++++++
+            STUDENT RECORD MENU               +
+++++++++++++++++++++++++++++++++++++++++++++++++
+  a/A  : add new record                       +
+  d/D  : delete a record                      +
+  s/S  : show the list                        +
+  m/M  : modify a record                      +
+  t/T  : sort the list                        +
+  l/L  : delete all records                   +
+  r/R  : reverse the list                     +
+  v/V  : save                                 +
+  e/E  : exit                                 +
+++++++++++++++++++++++++++++++++++++++++++++++++
```

---

## 🔐 Data File & Permissions

After the first save, the data file is automatically locked:

```bash
ls -l ~/.dbase/student.dat
# -r--r----- 1 root <youruser> ... student.dat
```

| Who | Can Read | Can Write | Can Delete |
|---|---|---|---|
| Root | ✅ | ✅ | ✅ |
| Owner (user) | ✅ | ❌ | ❌ |
| Others | ❌ | ❌ | ❌ |

```bash
# Normal user trying to delete → blocked
rm ~/.dbase/student.dat
# rm: cannot remove: Permission denied ✅

# Root purge → works
sudo dbase --purge
# Database purged successfully! ✅
```

---

## 🗂️ Data Structure

```c
struct Student {
    char  name[50];        // Student's full name
    int   rollno;          // Unique roll number
    float percentage;      // Academic percentage
    SLL  *next;            // Pointer to next node (linked list)
};
```

Records stored in `~/.dbase/student.dat` as plain text:
```
1 Gopi 92.50
2 Shankar 87.00
3 Kumar 78.75
```

---

## 🔧 Makefile Targets

```bash
make                  # Compile all source files → ./dbase
sudo make install     # Install to /sbin/dbase (root:root 755)
sudo make uninstall   # Remove /sbin/dbase
make clean            # Remove all .o files and binary
```

---

## 📌 .gitignore

```gitignore
# Compiled output
*.o
dbase

# Data file (user-specific, not for repo)
student.dat
.dbase/
```

---

## 👤 Author

**Ruby Shankar V**
GitHub: [@Ruby-Shankar-V](https://github.com/Ruby-Shankar-V)

---

## 📄 Version History

| Version | Description |
|---|---|
| v1.0 | Menu-driven mini project with local `student.dat` |
| v2.0 | Linux CLI utility (`dbase`) — `/sbin` install, root-protected storage, CLI args |

---

## 📄 License

This project is open source and available for educational and reference purposes.
