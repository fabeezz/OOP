class Coffee { }
class RegularCoffee : Coffee { }
class CreamCoffe : Coffee { }

// class CoffeeFactory
// {
//     virtual Coffee MakeCoffee()
//     {
//         return new Coffee();
//     }
// }

// public class RegularCoffeeFactory
// {
//     protected override Coffee MakeCoffee()
//     {
//         return new RegularCoffee();
//     }
// }

// public class CreamCoffeeFactory
// {
//     protected override Coffee MakeCoffee()
//     {
//         return new CreamCoffee();
//     }
// }

interface IFactory
{
    RegularCoffee MakeRegularCoffee();
    CreamCoffe MakeCreamCoffee();
}

class Client
{
    private readonly IFactory factory;

    public Client(IFactory factory)
    {
        this.factory = factory;
    }

    void GetCoffee()
    {
        RegularCoffeeFactory f = new RegularCoffeeFactory();
        Coffee coffee = f.MakeCoffee();
        CreamCoffeeFactory f2 = new CreamCoffeeFactory();
        Coffee coffee2 = f2.MakeCoffee();
    }
}