// Solution for Simple Bank System in CPP

class Bank {
public:

    unordered_map<int, long long> accToBalance;

    Bank(vector<long long>& balance) {
        for (int i = 0; i < balance.size(); i++) {
            accToBalance[i + 1] = balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (!accToBalance.count(account1) || !accToBalance.count(account2) || 
            accToBalance[account1] < money) {
            return false;
        }
        accToBalance[account1] -= money;
        accToBalance[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!accToBalance.count(account)) {
            return false;
        }
        accToBalance[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!accToBalance.count(account) || accToBalance[account] < money) {
            return false;
        }
        accToBalance[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
