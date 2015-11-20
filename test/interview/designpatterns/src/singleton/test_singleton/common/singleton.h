//file singleton.h
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
/***************************************************************************************************
* 1�� File       �� singleton.h
* 2�� Version    �� ��ʵ��ģʽģ����
* 3�� Description�� 
* 4�� Author     �� ray 
* 5�� Created    �� 15/9/6 15:06:00
* 6�� History    �� 
* 7�� Remark     �� ����ģʽ��һ�ֳ��õ�������ģʽ��
*                   �����ĺ��Ľṹ��ֻ����һ������Ϊ������������ࡣ
*                   ͨ������ģʽ���Ա�֤ϵͳ��һ����ֻ��һ��ʵ�����Ҹ�ʵ�����������ʣ��Ӷ������ʵ�������Ŀ��Ʋ���Լϵͳ��Դ��
*                   ���ϣ����ϵͳ��ĳ����Ķ���ֻ�ܴ���һ��������ģʽ����õĽ��������
****************************************************************************************************/

namespace COMMON
{
    template <typename _Ty>
    class Singleton
    {
    public:
        Singleton() {}
        virtual ~Singleton() {}

    public:
        static _Ty* getInstance()
        {
            static _Ty t;
            return &t;
        }

    private:
        // explicit���캯��ֻ�ܱ���ʽ���� ����������� explicit�ؼ���ֻ�������๹�캯��
        Singleton(_Ty const &);                                            // ���ÿ������캯��    explicit����Ҫ��Ϊ��������δʵ��������ʽ��Ҳ����Ҫ������
        _Ty& operator=(_Ty const &) const;                                 // ���أ���������Խ��ã���ֵ
    };
}

#endif // __SINGLETON_H__