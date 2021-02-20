/*

Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads. Thread A will call foo() while thread B will call bar(). Modify the given program to output "foobar" n times.

*/

//using System.Threading;
public class FooBar {
    private int n;

    //
    int printFoo_ = 1;
    int printBar_ = 2;
    int state = 1;
    
    // used as lock
    static readonly object lk = new object();  
    //
    
    public FooBar(int n) {
        //Console.WriteLine(n);
        this.n = n;
    }

    public void Foo(Action printFoo) {
        
        for (int i = 0; i < n; /*i++*/) 
        {
            
            lock(lk)
            {
                //Console.WriteLine("F");
                if (state == printFoo_)
                {
                    printFoo();
                    state = printBar_;
                    i++;
                }
            }
        }
    }

    public void Bar(Action printBar) {
        
        for (int i = 0; i < n; /*i++*/) 
        {

            lock(lk)
            {
               //Console.WriteLine("B");
               if (state == printBar_)
                {
                    printBar();
                    state = printFoo_;
                    i++;
                } 
            }
        } // end for
    } // end func
    
    
}
