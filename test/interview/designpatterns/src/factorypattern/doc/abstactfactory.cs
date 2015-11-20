//3.抽象工厂: 

// 抽象工厂是应对产品族概念的。比如说，每个汽车公司可能要同时生产轿车，货车，客车，那么每一个工厂都要有创建轿车，货车和客车的方法。
// 应对产品族概念而生，增加新的产品线很容易，但是无法增加新的产品。
using System;

public interface IBusinessCar
{
    void run();
}

public interface ISportCar
{
    void run();
}

public class BMWBusinessCar : IBusinessCar
{
    public void run()
    {
        Console.WriteLine("BMWCar run");
    }


}

public class BenzBusinessCar : IBusinessCar
{
    public void run()
    {
        Console.WriteLine("BenzBusinessCar run");
    }
}

public class BMWSportCar : ISportCar
{
    public void run()
    {
        Console.WriteLine("BMWSportCar run");
    }
}

public class BenzSportCar : ISportCar
{
    public void run()
    {


        Console.WriteLine("BenzSportCar run");
    }
}

public interface IDriver
{
    IBusinessCar BusinessCarDriver();
    ISportCar SportCarDriver();
}

public class BMWDriver : IDriver
{
    public IBusinessCar BusinessCarDriver()
    {
        return new BMWBusinessCar();
    }
    public ISportCar SportCarDriver()
    {
        return new BMWSportCar();
    }
}

public class BenzDriver : IDriver
{
    public IBusinessCar BusinessCarDriver()
    {
        return new BenzBusinessCar();
    }

    public ISportCar SportCarDriver()
    {
        return new BenzSportCar();
    }
}



class Client
{
    public static void Main()
    {
        IDriver myDriver = new BenzDriver();
        ISportCar myCar = myDriver.SportCarDriver();
        myCar.run();
        Console.Read();
    }

}

//心得:抽象方法似乎达到了完美境界.把开奔驰的司机和开宝马的司机的公共方法抽象出来,并对不同的司机创建不同的类,到时候不管是开什么车的司机随你添加.它们唯一的共同点都是开车.
