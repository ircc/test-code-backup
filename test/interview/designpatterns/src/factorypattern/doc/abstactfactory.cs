//3.���󹤳�: 

// ���󹤳���Ӧ�Բ�Ʒ�����ġ�����˵��ÿ��������˾����Ҫͬʱ�����γ����������ͳ�����ôÿһ��������Ҫ�д����γ��������Ϳͳ��ķ�����
// Ӧ�Բ�Ʒ���������������µĲ�Ʒ�ߺ����ף������޷������µĲ�Ʒ��
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

//�ĵ�:���󷽷��ƺ��ﵽ����������.�ѿ����۵�˾���Ϳ������˾���Ĺ��������������,���Բ�ͬ��˾��������ͬ����,��ʱ�򲻹��ǿ�ʲô����˾���������.����Ψһ�Ĺ�ͬ�㶼�ǿ���.
