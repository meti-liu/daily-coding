public class lab1_T6p 
{
    long times(int m)
    {
        if (m == 0 || m == 1) return 1;
        else
        {
            long ans = 1;
            for (int i = m; i >= 1; i--) ans *= i;
            return ans;
        }
    }
    long f(int m)
    {
        if(m==1) return 1;
        else return times(m)+f(m-1);
    }
    public static void main(String[] args)
    {
        lab1_T6p a=new lab1_T6p();
        System.out.println(a.f(20));
    }
}
