/****************** Client program *****************/
import java.net.*;
import java.io.*;

public class client {
static Socket server;

public static void main(String[] args) throws Exception {
   server = new Socket(InetAddress.getLocalHost(), 5679);
   BufferedReader receive = new BufferedReader(new InputStreamReader(server.getInputStream()));
   PrintWriter send = new PrintWriter(server.getOutputStream());
   BufferedReader wt = new BufferedReader(new InputStreamReader(System.in));

   while (true) {
    String str = wt.readLine();
    send.println(str);
    send.flush();
     
    System.out.println("send ok");
    String tem=receive.readLine();
    System.out.println(tem);

    if (str.equals("end")) {
     break;
    }
   }
   server.close();
  }
}

