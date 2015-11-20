//2.工厂方法: 
// 工厂方法是针对每一种产品提供一个工厂类。通过不同的工厂实例来创建不同的产品实例。
// 在同一等级结构中，支持增加任意产品。
// 

using System; 
public interface ICar 
{ 
    void run(); 
} 

public class BMWCar : ICar 
{ 
    public void run() 
    { 
        Console.WriteLine("BMWCar run"); 
    } 
} 

public class BenzCar : ICar 
{ 
    public void run() 
    { 
        Console.WriteLine("BenzCar run"); 
    } 
} 
public abstract class Driver 
{ 
    public abstract ICar DriverCar(); 
} 

public class BMWDriver : Driver 
{ 
    public override ICar  DriverCar() 
    { 
        return new BMWCar(); 
    } 

} 
public class BenzDriver : Driver 
{ 
    public  override ICar DriverCar() 
    { 
        return new BenzCar(); 
    } 
} 

class Client 
{ 
    public static void Main() 
    { 
        Driver myDriver = new BenzDriver(); 
        ICar myCar = myDriver.DriverCar(); 
        myCar.run(); 
        Console.Read(); 
    } 
}

//心得:优点是符合了开放-封闭原则(OCP),从整体上还看不出什么缺点.