-- Create a new database
CREATE DATABASE databaseName;

-- Use/select a database
USE databaseName;

-- Delete a database
DROP DATABASE databaseName;

-- Create a new table
CREATE TABLE users (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100),
    created_at DATETIME
);

-- Delete a table
DROP TABLE users;

-- View table structure
DESCRIBE users;

-- Add a column
ALTER TABLE users ADD age INT;

-- Modify a column type
ALTER TABLE users MODIFY age VARCHAR(10);

-- Rename a column (MySQL)
ALTER TABLE users CHANGE age user_age INT;

-- Drop a column
ALTER TABLE users DROP COLUMN user_age;

-- Insert data
INSERT INTO users (id, name, email, created_at)
VALUES (1, 'Mohammed', 'Mohammed@gmail.com', NOW());

-- Update data
UPDATE users SET name = 'Jane Doe' WHERE id = 1;

-- Delete data
DELETE FROM users WHERE id = 1;

-- Basic select
SELECT * FROM users;

-- Select specific columns
SELECT name, email FROM users;

-- With a condition
SELECT * FROM users WHERE email LIKE 'Mohammed@gmail.com';

-- Sorting
SELECT * FROM users ORDER BY name ASC;

-- Limit number of rows
SELECT * FROM users LIMIT 5;

-- Inner join two tables
SELECT users.name, orders.total
FROM users
JOIN orders ON users.id = orders.user_id;

-- Count users by domain
SELECT SUBSTRING_INDEX(email, '@', -1) AS domain, COUNT(*) AS user_count
FROM users
GROUP BY domain
HAVING user_count > 1;
