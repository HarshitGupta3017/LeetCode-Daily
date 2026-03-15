// Solution for Fancy Sequence in JAVA

class Fancy {

    private static final long MOD = 1_000_000_007;

    private List<Long> normalizedSequence = new ArrayList<>();

    private long currentAdder = 0;
    private long currentMultiplier = 1;

    private long modPower(long base, long exponent) {
        if (exponent == 0) return 1;

        long half = modPower(base, exponent / 2);
        long result = (half * half) % MOD;

        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }

    public Fancy() {}

    public void append(int val) {

        long normalizedValue =
                ((val - currentAdder) % MOD + MOD) % MOD
                * modPower(currentMultiplier, MOD - 2) % MOD;

        normalizedSequence.add(normalizedValue);
    }

    public void addAll(int inc) {
        currentAdder = (currentAdder + inc) % MOD;
    }

    public void multAll(int m) {
        currentAdder = (currentAdder * m) % MOD;
        currentMultiplier = (currentMultiplier * m) % MOD;
    }

    public int getIndex(int idx) {

        if (idx >= normalizedSequence.size())
            return -1;

        long value = (normalizedSequence.get(idx) * currentMultiplier + currentAdder) % MOD;

        return (int) value;
    }
}
