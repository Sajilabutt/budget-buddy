# Budget Buddy++

A console-based personal budget tracker built in C++, designed to help users track income, expenses, savings goals, and spending habits with friendly, real-time feedback.

## Features

- **Income tracking** — log income amounts and maintain a running total
- **Expense tracking** — log expenses by category (food, transport, clothes, games, other) with recursive entry (keep adding expenses without returning to the menu)
- **Category-based feedback** — fun, contextual comments based on what you spent on
- **Budget limit alerts** — warnings when you're approaching or have exceeded your set monthly budget
- **Savings goal tracking** — set a savings target and get live updates on your progress
- **Summary view** — see total income, total expenses, remaining balance, category breakdown, and a visual budget usage bar

## How It Works

The program runs on a menu-driven loop (`showMenu()`), recursively re-displaying itself after each action until the user chooses to exit. Core logic is split into focused functions:

- `addIncome()` — adds to the running income total
- `addExpense()` — logs an expense, categorizes it, checks budget/goal status, and recursively prompts for more expenses
- `giveComment()` — returns a category-specific message and updates category counters
- `setBudget()` / `setSavingsGoal()` — configure spending limits and savings targets
- `viewSummary()` — displays a full breakdown of income, expenses, balance, and category counts with a progress bar

## How to Run

Compile and run with any standard C++ compiler:

```bash
g++ project.cpp -o budget_buddy
./budget_buddy
```

On Windows (MinGW):
```bash
g++ project.cpp -o budget_buddy.exe
budget_buddy.exe
```

## Tech Stack

- C++ (console application)
- Core concepts: functions, recursion, conditionals, switch-case, basic state management
