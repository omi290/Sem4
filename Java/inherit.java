class box
{
    int l,b,h;
    box(int l,int b,int h)
    {
        this.l=l;
        this.b=b;
        this.h=h;
    }
    int vol(){
        return l*b*h;
    }
}
class boxW extends box
{
    int w;
    boxW(int w,int l,int b,int h)
    {
        super(l,b,h);
        this.w=w;
    }
}
public class inherit {
    public static void main(String args[]){
        boxW b = new boxW(10, 5, 2, 15);
        int v= b.vol();
        System.out.println(v +" "+ b.w);
    }
}
