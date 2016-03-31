public class HelloJni {
    public native void displayHelloJni();

    static {
        System.loadLibrary("helloJni");
    }

    public static void main(String[] args) {
        //System.out.println(System.getProperty("java.library.path"));
        new HelloJni().displayHelloJni();
    }
}