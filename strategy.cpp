class TaxStrategy
{
    public:
        virtual double Calculate(const Context &context) = 0;
        virtual ~TaxStrategy(){}
};

class CNTax:public TaxStrategy
{
    public:
        virtual double Calculate(const Context *context)
        {
            //...
        }
};

class USTax:public TaxStrategy
{
    public:
        virtual double Calculate(const Context *context)
        {
            //...
        }
};

//....更多的其余的Tax

class SalesOrder
{
    private:
        TaxStrategy *stratrgy;
    public:
        SalesOrder(StrategyFactory *strategyFactory)/*工厂模式*/
        {
            this->stratrgy = strategyFactory -> NewStrategy();
        }
        ~SalesOrder()
        {
            delete stratrgy;
        }
        double CalculateTax()
        {
            //...
            Context context();
            double val = stratrgy->Calculate(context);
            //...
        }
};

