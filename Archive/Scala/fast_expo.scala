def fast_pow(x : Int, y : Int):Int = {
 	if(y==0) return 1;
 	var p = fast_pow(x,y/2);
 	if(y%2!=0) x*p*p else p*p; 
}
print(fast_pow(2,3))