

public class SocketTester {
	
	public static void main(String[] args){
		try {
			ServerSocket serverSocket = new ServerSocket(7536);
			
			while (true){
				Socket socket=serverSocket.accept();
				socket.setSoTimeout(30000);
				
				BufferedInputStream in = new BufferedInputStream(socket.getInputStream());
				byte[] b = new byte[1024];
				int i = in.read(b);
				String str = new String(b, 0, i);
				System.out.println("RECEIVE MESSAGE£º"+str);
				
				BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
				System.out.println("SEND MESSAGE: 101010");
				out.write("101010");
				out.flush();
				
				in.close();
				out.close();
				socket.close();
		    }
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}