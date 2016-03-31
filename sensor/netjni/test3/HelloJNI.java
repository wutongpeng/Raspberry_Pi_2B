public class HelloJNI
{
    static
    {
        System.loadLibrary("goodluck");
    }
    public native static int get();
    public native static void set();
    public static void main(String[] args)
    {
        HelloJNI test = new HelloJNI();
        test.set();
        System.out.println(test.get());
    }
}


/*
*
*gcc -fPIC -D_REENTRANT -I/usr/lib/jvm/java-1.5.0-sun-1.5.0.19/include -I/usr/lib/jvm/java-1.5.0-sun-1.5.0.19/include/linux -c HelloJNI.c
*
*gcc -Wall -o libgoodluck.so  HelloJNI.c -D_REENTRANT -shared -fPIC -I/usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/include/ -I/usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/include/linux -lwiringPi
*/


/*
*Java HotSpot(TM) Client VM warning: You have loaded 
*library /root/jni/libgoodluck.so which might have disabled stack guard. The VM will try to fix the stack guard now.
*/