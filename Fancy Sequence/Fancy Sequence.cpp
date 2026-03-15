// Solution for Fancy Sequence in CPP

class Fancy {
public:

    using ll = long long;

    // Modulo required by the problem
    const ll MOD = 1e9 + 7;

    /*
        Instead of storing the actual sequence values,
        we store "normalized values".

        Why?

        Because operations addAll() and multAll() apply
        to EVERY element in the sequence.

        If we updated the whole vector each time,
        complexity would become O(n) per operation.

        So we store values in a transformed form and
        maintain two global parameters:

        currentMultiplier
        currentAdder

        Final value of any element becomes:

        actualValue = storedValue * currentMultiplier + currentAdder
    */
    vector<ll> normalizedSequence;

    // Represents global addition applied to all elements
    ll currentAdder = 0;

    // Represents global multiplication applied to all elements
    ll currentMultiplier = 1;

    /*
        Fast modular exponentiation.

        Used to compute modular inverse via:
        a^(MOD-2) % MOD  (Fermat's Little Theorem)

        Since MOD is prime.
    */
    ll modPower(ll base, ll exponent) {

        if (exponent == 0)
            return 1;

        ll half = modPower(base, exponent / 2);

        ll result = (half * half) % MOD;

        if (exponent % 2 == 1)
            result = (result * base) % MOD;

        return result;
    }

    Fancy() {
        // Initially sequence is empty
    }

    /*
        append(val)

        We need to insert a value such that:

        storedValue * currentMultiplier + currentAdder = val

        Solve for storedValue:

        storedValue = (val - currentAdder) / currentMultiplier

        Since division in modular arithmetic requires
        multiplying by modular inverse:

        storedValue = (val - currentAdder) * inverse(currentMultiplier)
    */
    void append(int val) {

        ll normalizedValue =
            ((val - currentAdder) % MOD + MOD) * 
            modPower(currentMultiplier, MOD - 2) % MOD;

        normalizedSequence.push_back(normalizedValue);
    }

    /*
        addAll(inc)

        Instead of updating every element,
        we simply increase the global adder.
    */
    void addAll(int inc) {

        currentAdder = (currentAdder + inc) % MOD;
    }

    /*
        multAll(m)

        When multiplying the whole sequence:

        (x * currentMultiplier + currentAdder) * m

        becomes

        x * (currentMultiplier * m) + (currentAdder * m)

        So we update both transformation parameters.
    */
    void multAll(int m) {

        currentAdder = (currentAdder * m) % MOD;
        currentMultiplier = (currentMultiplier * m) % MOD;
    }

    /*
        getIndex(idx)

        Retrieve stored normalized value and apply
        the transformation to get the real value.
    */
    int getIndex(int idx) {

        if (idx >= normalizedSequence.size())
            return -1;

        return (normalizedSequence[idx] * currentMultiplier + currentAdder) % MOD;
    }
};
