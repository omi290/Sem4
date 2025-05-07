class Buffer{
    int data;
    boolean isEmpty=true;
    public synchronized  void produce(int v){
        while(!isEmpty){
            try{
                wait();
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }
        }
        data = v;
        System.out.println("producer produced :"+data);
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
        System.out.println("Consumer consumed :"+data);
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
            buffer.produce(i);
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
public class program {
    public static void main(String [] args){
        Buffer b=new Buffer();
        Producer p= new Producer(b);
        Consumer c = new Consumer(b);
        p.start();
        c.start();
    }
}
