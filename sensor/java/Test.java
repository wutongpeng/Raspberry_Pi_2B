import com.pi4j.io.gpio.GpioController;  
import com.pi4j.io.gpio.GpioFactory;  
import com.pi4j.io.gpio.GpioPinDigitalOutput;  
import com.pi4j.io.gpio.PinState;  
import com.pi4j.io.gpio.RaspiPin;  
  
/** 
 * 控制树莓派上的GPIO实例 
 * @author 亓根火柴 
 */  
public class Test {  
      
    public static void main(String[] args) throws InterruptedException {  
        // 创建一个GPIO控制器  
       final GpioController gpio = GpioFactory.getInstance();  
          
        // 获取1号GPIO针脚并设置高电平状态，对应的是树莓派上的12号针脚，可以参考pi4j提供的图片。  
       final GpioPinDigitalOutput pin = gpio.provisionDigitalOutputPin(RaspiPin.GPIO_01, "LED", PinState.HIGH);  
  
    while(true){  
        //设置高电平  
        pin.high();  
        System.out.println("打开继电器");  
        //睡眠1秒  
           Thread.sleep(1000);  
        //设置低电平  
        pin.low();  
        System.out.println("关闭继电器");  
           Thread.sleep(1000);  
        //切换状态  
           //pin.toggle();  
    }  
    }  
}  
