#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>   // for time()
using namespace std;
float income = 0, expenses = 0, budgetLimit = 0, savingsGoal = 0;
int foodCount = 0, transportCount = 0, clothesCount = 0, otherCount = 0;
bool goalSet = false;

void giveComment(string purpose)
 {
    if (purpose == "food") {
        cout << " Food is fuel! Just don’t let your cravings eat your wallet too.\n";
        foodCount++;
    } else if (purpose == "transport") {
        cout << " Travel smart, save more!\n";
        transportCount++;
    } else if (purpose == "clothes") {
        cout << " Looking sharp! Just keep an eye on those price tags.\n";
        clothesCount++;
    } else if (purpose == "games") {
        cout << " A little fun is okay — just budget your joy!\n";
        otherCount++;
    } 
     else {
        cout << " Every rupee counts. Keep tracking and you'll stay in control!\n";
        otherCount++;
    }
}

void addIncome() {
    float amt;
    cout << "\nEnter income amount: ";
    cin >> amt;
    income = income + amt;
    cout << "Income updated successfully!\n";
}

void addExpense(); // forward declaration for recursion

void addExpense() {
    float amt;
    string purpose;

    cout << "\nEnter expense amount: ";
    cin >> amt;
    cout << "What did you spend on? ";
    cin >> purpose;

    expenses += amt;
    giveComment(purpose);

    if (budgetLimit > 0 && expenses > budgetLimit) {
        cout << " Budget limit exceeded! You spent Rs. " << expenses << ".\n";
    } else if (budgetLimit > 0 && expenses >= budgetLimit * 0.9) {
        cout << " You're about to hit your budget limit. Be cautious!\n";
    }

    if (goalSet) {
        float saved = income - expenses;
        if (saved >= savingsGoal) {
            cout << " Congrats! You’ve reached your savings goal of Rs. " << savingsGoal << "!\n";
        } else {
            cout << "You are Rs. " << (savingsGoal - saved) << " away from your goal.\n";
        }
    }

    char more;
    cout << "Do you want to add another expense? (y/n): ";
    cin >> more;
    if (more == 'y' || more == 'Y') {
        addExpense();
    }
}

void viewSummary() {
    float balance = income - expenses;
    cout << "\n--- Budget Summary ---\n";
    cout << "Total Income: Rs. " << income << endl;
    cout << "Total Expenses: Rs. " << expenses << endl;
    cout << "Remaining Balance: Rs. " << balance << endl;

    cout << "\nBreakdown by category:\n";
    cout << "Food: " << foodCount << " times\n";
    cout << "Transport: " << transportCount << " times\n";
    cout << "Clothes: " << clothesCount << " times\n";
    cout << "Other: " << otherCount << " times\n";

    if (budgetLimit > 0) {
        float percent = (expenses / budgetLimit) * 100;
        cout << "\nBudget used: [";
        int bars = percent / 10;
        for (int i = 0; i < 10; i++) {
            if (i < bars) cout << "¦"; else cout << "¦";
        }
        cout << "] (" << percent << "%)\n";
    }
}

void setBudget() {
    cout << "\nEnter your monthly budget limit: ";
    cin >> budgetLimit;
    cout << "Budget set successfully!\n";
}

void setSavingsGoal() {
    cout << "\nEnter your savings goal: ";
    cin >> savingsGoal;
    goalSet = true;
    cout << "Goal set! Save smartly.\n";
}

void showMenu();

void showMenu() {
    int choice;
    cout << "\n\n========= Budget Buddy++ =========\n";
    cout << "1. Add Income\n";
    cout << "2. Add Expense\n";
    cout << "3. View Summary\n";
    cout << "4. Set Monthly Budget\n";
    cout << "5. Set Savings Goal\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
    cin >> choice;

    switch (choice) {
        case 1: addIncome(); break;
        case 2: addExpense(); break;
        case 3: viewSummary(); break;
        case 4: setBudget(); break;
        case 5: setSavingsGoal(); break;
        case 6:
            cout << "\nThanks for using Budget Buddy++. Stay smart with your money!\n";
            return;
        default:
            cout << "Invalid option. Try again.\n";
    }

    showMenu(); // Recursive call to show menu again
}

int main() {
    cout << "Welcome to Budget Buddy++!\n";
    showMenu();
    return 0;
}
