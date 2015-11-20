 //1.�򵥹���: 
 // �򵥹���ģʽ�Ĺ�����һ����ʹ�þ�̬������ͨ�����յĲ����Ĳ�ͬ�����ز�ͬ�Ķ���ʵ����
 // ���޸Ĵ���Ļ������޷���չ�ġ�
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

//�ĵ�:�ŵ���ֻҪʵ�ֹ��еĽӿھͿ���ʵ�ֲ�ͬ���ܵķ�ʽ.��ȱ�����Ҫ�ж���һ�ֳ�,���Ҫ�޸�Driver ��