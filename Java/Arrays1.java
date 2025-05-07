class Buffer{
    int data[]=new int[10];
    boolean isEmpty=true;
    public synchronized  void produce(){
        while(!isEmpty){
            try{
                wait();
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }
        }
        for(int i=0;i<10;i++){
            data[i]=i+1;
            System.out.println("producer produced :"+data[i]);
        }
        
        isEmpty=false;
        notify();
    }
    public synchronized void consume(){
        while(isEmpty){
            try{
                wait();
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }
        }
        for(int i=0;i<10;i++){
            System.out.println("Consumer consumed :"+data[i]);
        }
        
        isEmpty=true;
        notify();
    }
}
class Producer extends Thread{
    Buffer buffer;
    public Producer(Buffer buffer){
        this.buffer=buffer;
    }
    public void run(){
        for(int i =1;i<=5;i++){
            buffer.produce();
            try{
                Thread.sleep(500);
            }
            catch (InterruptedException e){
                e.printStackTrace();
            }
        }
    }

}
class Consumer extends Thread{
    Buffer buffer;
    public Consumer(Buffer buffer){
        this.buffer=buffer;
    }
    public void run(){
        for(int i =1;i<=5;i++){
            buffer.consume();
            try{
                Thread.sleep(800);
            }
            catch (InterruptedException e){
                e.printStackTrace();
            }
        }
    }

}
public class Arrays1 {
    public static void main(String [] args){
        Buffer b=new Buffer();
        Producer p= new Producer(b);
        Consumer c = new Consumer(b);
        p.start();
        c.start();
    }
}
