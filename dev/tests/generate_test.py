for a in range(30):
	for b in range(30):
		for o in ["*", "/", "+", "-", "%", "^", "**", "#"]:
			l = "t" + ("00" + str(a))[-2:]
			r = "t" + ("00" + str(b))[-2:]
			print (l + " " + o + " " + r)
