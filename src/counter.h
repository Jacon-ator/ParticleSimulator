struct Counter {
    public:
        Counter() {};

        int getAmount()
        {
            return amount;
        } 

        void increment(int value = 1)
        {
            amount += value;
        }

        void decrement(int value)
        {
            amount -= value;
        }

    private:
        int amount = 0;
};