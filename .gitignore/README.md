# Research
DEVELOPMENT OF IOT BASED MONITORING AND SMART ANALYZING DEVICE FOR AGRICULTURE 
<?php
//this is slavar.php
//http://127.0.0.1/nodemcu/save.php?suboda=paja methana pass wena variable eke nama danne

// use save.php"?subo=subod" to save data
//http://127.0.0.1/nodemcu/save.php?subo=paja&subo2= kamathiekak&subo2=ok when u save more data 
	$subo = $_GET['suboda'];
	//$subo1 = $_GET['subo1'];
	//$subo2 = $_GET['subo2'];


	$sql = "INSERT INTO data (subo) VALUES (:subod)";
		//$sql = "INSERT INTO data (subo, subo1,subo2) VALUES (:subo, :subo1, :subo2)";
	$stmt =  $PDO->prepare($sql);

	$stmt-> bindParam(':subo',$subod);
	//$stmt-> bindParam(':subo1',$subod1);
	//$stmt-> bindParam(':subo2',$subod2);

	if($stmt->execute()){
		echo "ok data save";

	}else{
		echo "error in saving";
	}
?>
