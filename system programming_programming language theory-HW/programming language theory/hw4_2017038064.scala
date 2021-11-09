val my_list = List (1,2,3,4)
val my_odd_list = List (1,3,5,7)
val addone = (x : Int) =>x+1
val iseven = (x: Int) => x%2==0

//////////////////Problem 1///////////////////////////////////////////

def uncurry[A,B,C,D](f : A => B=> C=> D) : (A,B,C) => D =
{
  (a:A,b:B,c:C)=>f(a)(b)(c)
}
val sum3 = (x :Int) => (y : Int) => (z : Int) => x+y+z
val sum3_middle  = uncurry (sum3)
println("" + sum3_middle(3, 5, 7)+"")  // print 15

//////////////////////////Problem 2/////////////////////////////////

def myexists (list : List[Int], f:Int => Boolean) : Boolean = 
{
    if(f(list(0))==true)true
    else{
      if(list.length!=1)
        myexists(list.tail,f)
      else
        false
    }
}
println (""+myexists(my_list, iseven)+"") //print true
println (""+myexists(my_odd_list, iseven)+"") //print falase

//////////////Problem3//////////////////////////////////////////

def myfilter(list : List[Int], f:Int => Boolean) : List[Int] = 
{
  for(i<-list; if(f(i)==true))yield i
}
println (""+myfilter(my_list, iseven)+"") //print List(2,4)
