//2.��������: 
// �������������ÿһ�ֲ�Ʒ�ṩһ�������ࡣͨ����ͬ�Ĺ���ʵ����������ͬ�Ĳ�Ʒʵ����
// ��ͬһ�ȼ��ṹ�У�֧�����������Ʒ��
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

//�ĵ�:�ŵ��Ƿ����˿���-���ԭ��(OCP),�������ϻ�������ʲôȱ��.