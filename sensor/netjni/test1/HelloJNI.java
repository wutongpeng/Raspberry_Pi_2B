public class HelloJNI
{
    static
    {
        System.loadLibrary("goodluck");
    }
    public native static int get();
    public native static void set(int i);
    public static void main(String[] args)
    {
        HelloJNI test = new HelloJNI();
        test.set(0);
        System.out.println(test.get());
    }
}
