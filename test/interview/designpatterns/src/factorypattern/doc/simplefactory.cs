 //1.简单工厂: 
 // 简单工厂模式的工厂类一般是使用静态方法，通过接收的参数的不同来返回不同的对象实例。
 // 不修改代码的话，是无法扩展的。
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

public class Driver 
{ 
    public static ICar DriverCar(string carType) 
    { 
        switch (carType) 
        { 
            case "BMWCar": return new BMWCar(); 
            case "BenzCar": return new BenzCar(); 
            default: throw new Exception(); 
       } 
    } 
} 

public class Client 
{ 
    public static void Main() 
    { 
        ICar myCar = Driver.DriverCar("BenzCar"); 
        myCar.run(); 
        Console.Read(); 
    } 
} 

//心得:优点是只要实现共有的接口就可以实现不同车跑的方式.但缺点就是要判断哪一种车,造成要修改Driver 类