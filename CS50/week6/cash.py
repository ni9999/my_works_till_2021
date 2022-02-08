def main():
	total_coin = 0
	doller = 0
	print ("hello cash")
	while doller <= 0:
		doller = float (input ("Cash : "))
	tmp = doller *100
	bucks = int(tmp % 100)
	coin = [25, 10, 5, 1]
	for i in range(4):
		coins=coin_count(bucks,coin[i])
		total_coin = total_coin + coins
		bucks = bucks - coins*coin[i]
	print (f"coin : {total_coin}")
	
	
def coin_count(bucks,value):
	coinlocal = 0
	if(bucks>=value):
		coinlocal = int(bucks / value)
	return coinlocal
		
main()
