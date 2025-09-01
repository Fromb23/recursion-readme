# Personal Finance Manager - MySQL Database Project

## 🎯 Project Overview
Build a comprehensive Personal Finance Manager application using MySQL database that helps users track income, expenses, savings goals, and generate financial reports. This project is designed to introduce database concepts through a modular, step-by-step implementation that emphasizes hands-on learning.

## 📚 Database Concepts Covered
- **Database Fundamentals**: What are databases, RDBMS vs NoSQL
- **MySQL Basics**: Installation, configuration, basic operations
- **SQL Operations**: CREATE, INSERT, SELECT, UPDATE, DELETE
- **Database Design**: Tables, relationships, primary/foreign keys
- **Data Types**: VARCHAR, INT, DECIMAL, DATE, DATETIME
- **Constraints**: NOT NULL, UNIQUE, CHECK constraints
- **Joins**: INNER, LEFT, RIGHT joins for related data
- **Indexing**: Performance optimization basics
- **Python-MySQL Integration**: Using mysql-connector-python
- **Error Handling**: Database-specific exception handling
- **Transactions**: ACID properties and commit/rollback

---

## 🔧 Prerequisites & Setup

### Required Software
1. **Python 3.8+** (already installed)
2. **MySQL Server 8.0+** 
3. **MySQL Workbench** (optional but recommended)
4. **VS Code** with Python and MySQL extensions

### Python Libraries to Install
```bash
pip install mysql-connector-python
pip install python-dotenv
pip install tabulate
```

### MySQL Installation Guide (Windows)
1. Download MySQL Installer from [mysql.com](https://dev.mysql.com/downloads/installer/)
2. Run installer and select "Developer Default"
3. Set root password (remember this!)
4. Complete installation
5. Verify installation by opening Command Prompt and typing: `mysql --version`

---

## 📋 Project Structure

```
personal_finance_mysql/
├── README.md
├── .env                    # Database credentials (DO NOT commit to git)
├── requirements.txt        # Python dependencies
├── sql/
│   ├── create_database.sql # Database schema
│   └── sample_data.sql     # Sample data for testing
├── src/
│   ├── 00_database_intro.py
│   ├── 01_mysql_setup.py
│   ├── 02_database_connection.py
│   ├── 03_table_creation.py
│   ├── 04_basic_operations.py
│   ├── 05_user_management.py
│   ├── 06_account_management.py
│   ├── 07_transaction_management.py
│   ├── 08_category_management.py
│   ├── 09_reporting_queries.py
│   ├── 10_advanced_queries.py
│   ├── 11_data_validation.py
│   ├── 12_backup_restore.py
│   └── 13_complete_application.py
└── config/
    └── database_config.py
```

---

## 📚 Learning Modules

### Module 0: Database Introduction and Concepts
**File:** `00_database_intro.py`

**Learning Objectives:**
- Understand what databases are and why we need them
- Learn the difference between RDBMS and NoSQL
- Understand basic database terminology

**Hands-on Tasks:**
1. Create a simple file-based data storage system
2. Identify problems with file-based storage
3. Compare with database solutions
4. Write functions to demonstrate CRUD operations on Python data structures

**Key Concepts:**
- Data vs Information
- RDBMS (Relational Database Management System)
- NoSQL databases
- ACID properties
- Primary keys and foreign keys

---

### Module 1: MySQL Installation and Setup
**File:** `01_mysql_setup.py`

**Learning Objectives:**
- Install and configure MySQL on Windows
- Understand MySQL service management
- Learn basic MySQL command-line operations

**Hands-on Tasks:**
1. Verify MySQL installation
2. Start/stop MySQL service using Windows services
3. Connect to MySQL using command line
4. Create your first database
5. Show databases and tables

**Key Concepts:**
- MySQL Server vs MySQL Client
- Root user and privileges
- MySQL command-line client
- Basic SQL commands (SHOW, CREATE, USE)

---

### Module 2: Database Connection with Python
**File:** `02_database_connection.py`

**Learning Objectives:**
- Connect Python applications to MySQL
- Handle database connection errors
- Implement connection pooling basics

**Hands-on Tasks:**
1. Install mysql-connector-python
2. Create database connection class
3. Test connection with error handling
4. Create environment configuration file
5. Implement connection retry logic

**Key Concepts:**
- Database drivers
- Connection strings
- Environment variables for security
- Connection pooling
- Exception handling for databases

---

### Module 3: Table Creation and Schema Design
**File:** `03_table_creation.py`

**Learning Objectives:**
- Design database schema for finance application
- Create tables with appropriate data types
- Implement constraints and relationships

**Hands-on Tasks:**
1. Design ER diagram for Personal Finance Manager
2. Create Users table
3. Create Accounts table
4. Create Categories table
5. Create Transactions table
6. Add foreign key relationships
7. Create indexes for performance

**Key Concepts:**
- Entity-Relationship modeling
- Data types (VARCHAR, INT, DECIMAL, DATE, DATETIME)
- Primary keys and auto-increment
- Foreign keys and referential integrity
- Constraints (NOT NULL, UNIQUE, CHECK)
- Indexes and performance

---

### Module 4: Basic CRUD Operations
**File:** `04_basic_operations.py`

**Learning Objectives:**
- Implement Create, Read, Update, Delete operations
- Use parameterized queries for security
- Handle SQL injection prevention

**Hands-on Tasks:**
1. Insert sample users
2. Insert sample accounts
3. Insert sample categories
4. Insert sample transactions
5. Query data with SELECT statements
6. Update existing records
7. Delete records safely
8. Implement data validation

**Key Concepts:**
- SQL CRUD operations
- Parameterized queries
- SQL injection prevention
- Data validation
- Error handling for database operations

---

### Module 5: User Management System
**File:** `05_user_management.py`

**Learning Objectives:**
- Create user registration and authentication
- Implement user profile management
- Handle user data securely

**Hands-on Tasks:**
1. Create User class with database methods
2. Implement user registration
3. Implement user login (simple version)
4. Update user profiles
5. Delete user accounts
6. List all users with pagination

**Key Concepts:**
- User authentication basics
- Data privacy and security
- CRUD operations for user management
- Pagination with LIMIT and OFFSET
- Class-based database operations

---

### Module 6: Account Management System
**File:** `06_account_management.py`

**Learning Objectives:**
- Manage different types of financial accounts
- Implement account balance calculations
- Handle account relationships

**Hands-on Tasks:**
1. Create Account class with database methods
2. Add new accounts for users
3. Update account information
4. Calculate account balances from transactions
5. List accounts by user
6. Implement account types (checking, savings, credit)
7. Account summary reports

**Key Concepts:**
- One-to-many relationships (User to Accounts)
- Calculated fields and aggregations
- Account types and business logic
- Data consistency

---

### Module 7: Transaction Management System
**File:** `07_transaction_management.py`

**Learning Objectives:**
- Record and manage financial transactions
- Implement transaction categories
- Calculate running balances

**Hands-on Tasks:**
1. Create Transaction class with database methods
2. Record income transactions
3. Record expense transactions
4. Update transaction details
5. Delete transactions with balance recalculation
6. Search transactions by date range
7. Filter transactions by category
8. Calculate account balances

**Key Concepts:**
- Complex database relationships
- Date and time handling in SQL
- Aggregate functions (SUM, COUNT, AVG)
- Filtering with WHERE clauses
- Ordering with ORDER BY

---

### Module 8: Category Management and Analysis
**File:** `08_category_management.py`

**Learning Objectives:**
- Manage expense and income categories
- Analyze spending patterns by category
- Implement category-based reporting

**Hands-on Tasks:**
1. Create Category class with database methods
2. Add custom categories for users
3. Update category information
4. Delete categories (with transaction handling)
5. Generate spending analysis by category
6. Create monthly category reports
7. Implement category budgets

**Key Concepts:**
- Data relationships and constraints
- GROUP BY clauses for analysis
- Handling cascading deletes
- Business logic implementation
- Reporting and analytics

---

### Module 9: Financial Reporting and Queries
**File:** `09_reporting_queries.py`

**Learning Objectives:**
- Create comprehensive financial reports
- Use advanced SQL queries
- Implement data visualization preparation

**Hands-on Tasks:**
1. Monthly income/expense summary
2. Account balance history
3. Top spending categories report
4. Income vs expense trends
5. Savings rate calculations
6. Custom date range reports
7. Export reports to CSV

**Key Concepts:**
- Complex SELECT statements
- Subqueries and derived tables
- Date functions in MySQL
- Data export and formatting
- Performance optimization

---

### Module 10: Advanced Database Operations
**File:** `10_advanced_queries.py`

**Learning Objectives:**
- Implement advanced SQL features
- Use joins effectively
- Create stored procedures (basic)

**Hands-on Tasks:**
1. Multi-table joins for comprehensive reports
2. Subqueries for complex filtering
3. Window functions for running totals
4. Create simple stored procedures
5. Implement database views
6. Use CASE statements for conditional logic
7. Advanced filtering and search

**Key Concepts:**
- JOIN operations (INNER, LEFT, RIGHT)
- Subqueries and correlated subqueries
- Window functions
- Stored procedures basics
- Database views
- Advanced SQL functions

---

### Module 11: Data Validation and Integrity
**File:** `11_data_validation.py`

**Learning Objectives:**
- Implement comprehensive data validation
- Handle database constraints
- Ensure data integrity

**Hands-on Tasks:**
1. Client-side data validation
2. Database constraint validation
3. Custom validation rules
4. Error handling for constraint violations
5. Data sanitization
6. Implement data consistency checks
7. Create validation utility functions

**Key Concepts:**
- Data validation strategies
- Database constraints enforcement
- Error handling patterns
- Data sanitization
- Business rule validation

---

### Module 12: Backup and Data Management
**File:** `12_backup_restore.py`

**Learning Objectives:**
- Implement database backup strategies
- Handle data export/import
- Manage database maintenance

**Hands-on Tasks:**
1. Create database backup functionality
2. Implement data export to CSV/JSON
3. Create data import from external files
4. Database cleanup procedures
5. Data archiving strategies
6. Recovery procedures
7. Database maintenance tasks

**Key Concepts:**
- Database backup strategies
- Data migration
- Data archiving
- Database maintenance
- Disaster recovery basics

---

### Module 13: Complete Application Integration
**File:** `13_complete_application.py`

**Learning Objectives:**
- Integrate all modules into a complete application
- Create user-friendly interface
- Implement application workflow

**Hands-on Tasks:**
1. Create main application class
2. Implement command-line interface
3. User authentication workflow
4. Complete transaction management workflow
5. Reporting dashboard
6. Data backup and restore workflow
7. Error handling throughout application
8. Application testing and validation

**Key Concepts:**
- Application architecture
- User interface design
- Workflow management
- Error handling strategies
- Testing and validation
- Code organization and modularity

---

## 🗄️ Database Schema

### Users Table
```sql
CREATE TABLE users (
    user_id INT PRIMARY KEY AUTO_INCREMENT,
    username VARCHAR(50) UNIQUE NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    full_name VARCHAR(100) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);
```

### Accounts Table
```sql
CREATE TABLE accounts (
    account_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT NOT NULL,
    account_name VARCHAR(100) NOT NULL,
    account_type ENUM('checking', 'savings', 'credit') NOT NULL,
    initial_balance DECIMAL(10,2) DEFAULT 0.00,
    current_balance DECIMAL(10,2) DEFAULT 0.00,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(user_id) ON DELETE CASCADE
);
```

### Categories Table
```sql
CREATE TABLE categories (
    category_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT NOT NULL,
    category_name VARCHAR(50) NOT NULL,
    category_type ENUM('income', 'expense') NOT NULL,
    description TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(user_id) ON DELETE CASCADE,
    UNIQUE KEY unique_user_category (user_id, category_name)
);
```

### Transactions Table
```sql
CREATE TABLE transactions (
    transaction_id INT PRIMARY KEY AUTO_INCREMENT,
    account_id INT NOT NULL,
    category_id INT NOT NULL,
    amount DECIMAL(10,2) NOT NULL,
    transaction_type ENUM('income', 'expense') NOT NULL,
    description TEXT,
    transaction_date DATE NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (account_id) REFERENCES accounts(account_id) ON DELETE CASCADE,
    FOREIGN KEY (category_id) REFERENCES categories(category_id) ON DELETE RESTRICT
);
```

---

## 🚀 Getting Started

### Step 1: Environment Setup
1. Create project directory: `personal_finance_mysql`
2. Create virtual environment: `python -m venv venv`
3. Activate virtual environment: `venv\Scripts\activate` (Windows)
4. Install requirements: `pip install -r requirements.txt`
5. Create `.env` file with database credentials

### Step 2: MySQL Setup
1. Install MySQL Server and MySQL Workbench
2. Start MySQL service
3. Create database: `personal_finance_db`
4. Set up user credentials
5. Test connection

### Step 3: Project Configuration
1. Set up project constants and configuration
2. Create database connection utilities
3. Implement basic error handling
4. Test database connectivity

---

## 📝 Implementation Guidelines

### Code Organization
- Each module builds upon the previous one
- Use classes for database operations
- Implement proper error handling
- Include comprehensive comments
- Follow PEP 8 style guidelines

### Database Best Practices
- Use parameterized queries to prevent SQL injection
- Implement proper indexing for performance
- Use transactions for data consistency
- Handle database errors gracefully
- Implement connection pooling for efficiency

### Learning Approach
- **Read**: Understand the concept and requirements
- **Code**: Implement the solution step by step
- **Test**: Verify your implementation works correctly
- **Iterate**: Improve and optimize your code
- **Document**: Add comments explaining your logic

---

## 🎯 Learning Outcomes

By completing this project, you will:
- Understand fundamental database concepts
- Master MySQL installation and configuration
- Learn SQL query writing and optimization
- Implement Python-MySQL integration
- Build a complete database-driven application
- Understand database design principles
- Handle real-world database challenges
- Prepare for advanced database topics

---

## 📊 Assessment Criteria

### Technical Implementation (40%)
- Correct database schema design
- Proper SQL query implementation
- Effective Python-MySQL integration
- Error handling and validation

### Code Quality (30%)
- Clean, readable code
- Proper commenting and documentation
- Following Python best practices
- Modular code organization

### Functionality (20%)
- All required features implemented
- Application works as expected
- User interface is intuitive
- Data integrity maintained

### Learning Demonstration (10%)
- Understanding of database concepts
- Ability to explain design decisions
- Problem-solving approach
- Code evolution through modules

---

## 🔍 Testing Your Implementation

### Database Testing
1. Verify all tables are created correctly
2. Test all CRUD operations
3. Validate data relationships
4. Check constraint enforcement
5. Test error handling

### Application Testing
1. User registration and login
2. Account creation and management
3. Transaction recording and retrieval
4. Report generation
5. Data export/import functionality

---

## 🎓 Next Steps After Completion

1. **Performance Optimization**: Learn about query optimization and indexing
2. **Advanced SQL**: Stored procedures, triggers, views
3. **Database Security**: User roles, permissions, encryption
4. **Scaling**: Master-slave replication, partitioning
5. **NoSQL Exploration**: MongoDB, Redis for comparison
6. **ORM Framework**: SQLAlchemy for Python
7. **Web Integration**: Flask/Django with database backends

---

## 📚 Additional Resources

### MySQL Documentation
- [MySQL 8.0 Reference Manual](https://dev.mysql.com/doc/refman/8.0/en/)
- [MySQL Tutorial](https://www.mysqltutorial.org/)

### Python-MySQL Integration
- [mysql-connector-python Documentation](https://dev.mysql.com/doc/connector-python/en/)
- [Database Programming with Python](https://docs.python.org/3/library/sqlite3.html)

### SQL Learning Resources
- [W3Schools SQL Tutorial](https://www.w3schools.com/sql/)
- [SQLBolt Interactive Tutorial](https://sqlbolt.com/)

---

## ⚠️ Important Notes

### Security Considerations
- Never commit database credentials to version control
- Use environment variables for sensitive information
- Implement proper input validation
- Use parameterized queries to prevent SQL injection

### Development Best Practices
- Start with simple implementations and gradually add complexity
- Test each module thoroughly before moving to the next
- Keep your database schema documented
- Regular backups during development
- Version control your code (exclude .env file)

---

## 🎯 Success Metrics

You'll know you've mastered the basics when you can:
- ✅ Explain the difference between RDBMS and NoSQL
- ✅ Install and configure MySQL on your system
- ✅ Design and create a normalized database schema
- ✅ Write complex SQL queries with joins and subqueries
- ✅ Build a Python application that interacts with MySQL
- ✅ Handle database errors and edge cases
- ✅ Generate meaningful reports from your data
- ✅ Implement data backup and restore procedures

---

## 🤝 Getting Help

### When You're Stuck
1. Check the MySQL error log
2. Review your SQL syntax
3. Test queries in MySQL Workbench first
4. Use print statements to debug Python code
5. Search for specific error messages
6. Ask for help with specific error messages and code snippets

### Common Issues and Solutions
- **Connection refused**: Check if MySQL service is running
- **Access denied**: Verify username and password
- **Table doesn't exist**: Check if you're using the correct database
- **Syntax error**: Review SQL statement syntax
- **Import error**: Ensure mysql-connector-python is installed

---

Remember: Learning databases is like learning a new language. Start with simple queries and gradually build complexity. Practice regularly, and don't be afraid to experiment with different approaches!

Happy coding! 🚀