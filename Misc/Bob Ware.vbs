do
	'Defines Sites/pictures
	siteA = "https://youtu.be/dWscxdleZzI"
	siteB = "https://external-preview.redd.it/So8nAN-UONyjvdO5uy_jiQ-c53ZwTjD1jtN3DVbdC9E.jpg?auto=webp&s=32b054965ee6d134a167022ebb681e8e4481b83b"
	siteC= "https://i.imgflip.com/2oouy0.jpg"
	siteD="https://thoughtsonthedead.files.wordpress.com/2015/01/bobby-old-bird.jpg"
	siteE="https://i.pinimg.com/originals/8f/56/9c/8f569caf1c7980e973b2ae8b5388688a.jpg"
	siteZ="https://decider.com/wp-content/uploads/2016/05/bob-weir.jpg?quality=80&strip=all&w=646&h=431&crop=1"

	'Opens Youtube
	Set browobj = CreateObject("Wscript.Shell")
	browobj.Run "chrome -url "&siteA
	Set browobj = Nothing

	'Displays lyrics
	x=msgbox("Do You Want To Live In America?", 4+32, "ATTENTION")
	x=msgbox("All this hometown history is slippin' away, shattered by a miracle age!", 0+48, "God Bless Bob Weir")
		'Opens Picture of Bob Weir
	Set browobj = CreateObject("Wscript.Shell")
	browobj.Run "chrome -url "&siteB
	Set browobj = Nothing

	x=msgbox("I'm gonna roar through the night on a fantasy flight, AS SOON AS I COME OF AGE!!!", 0+64, "God Bless Bob Weir")
	x=msgbox("When the dream ignites, there's a flame so bright, burnin' in a young man's heart...", 0+64, "God Bless Bob Weir")
	x=msgbox("Get your hands on the wheel of some Detroit steel, you can hear the music start", 0+64, "God Bless Bob Weir")
	
	'Opens Up Youtube on every Chorus
	Set browobj = CreateObject("Wscript.Shell")
	browobj.Run "chrome -url "&siteA
	Set browobj = Nothing

	x=msgbox("I'm telling you I want to live in America I want to live in America", 0+64, "God Bless Bob Weir")
	x=msgbox( "I---------I want to live in America", 0+64, "God Bless Bob Weir")

	'Opens Picture of Bob Weir
	Set browobj = CreateObject("Wscript.Shell")
	browobj.Run "chrome -url "&siteD
	Set browobj = Nothing
	

	x=msgbox( "Have you ever been down south of Chinatown, seen the face of a refugee?", 3+16, "You Will...Survive")
	x=msgbox( "The kids are alive, they've learned to survive, they're just like you and me", 0+64, "God Bless Bob Weir")
	x=msgbox( "All their friends back home wonder what it's like alone, LIVING IN THE LAND OF THE FREE", 0+64, "God Bless Bob Weir")

	Set browobj = CreateObject("Wscript.Shell")
	browobj.Run "chrome -url "&siteA
	Set browobj = Nothing
	
	x=msgbox("I'm telling you I want to live in America I want to live in America", 0+64, "God Bless Bob Weir")
	x=msgbox( "I---------I want to live in America", 0+64, "God Bless Bob Weir")
	
	x=msgbox( "Where the electric guitars ring out loud, it's the heartbeat of the steet", 0+32, "God Bless Bob Weir")
	x=msgbox( "Where the engines scream and the music's mean, I just gotta feel the heat", 0+64, "God Bless Bob Weir")

	Set browobj = CreateObject("Wscript.Shell")
	browobj.Run "chrome -url "&siteA
	Set browobj = Nothing

	'Opens Picture of Bob Weir
	Set browobj = CreateObject("Wscript.Shell")
	browobj.Run "chrome -url "&siteE
	Set browobj = Nothing


	x=msgbox("I'm telling you I want to live in America I want to live in America", 0+64, "God Bless Bob Weir")
	x=msgbox( "I---------I want to live in America", 0+64, "God Bless Bob Weir")
	
	x=msgbox( "Where the electric guitars ring out loud, it's the heartbeat of the steet", 0+32, "God Bless Bob Weir")
	x=msgbox( "Where the engines scream and the music's mean, I just gotta feel the heat", 0+64, "God Bless Bob Weir")

	Set browobj = CreateObject("Wscript.Shell")
	browobj.Run "chrome -url "&siteZ
	Set browobj = Nothing

	x=msgbox("I'm telling you I want to live in America I want to live in America", 0+64, "God Bless Bob Weir")
	x=msgbox( "I---------I want to live in America", 2+16, "God Bless Bob Weir")
loop
