<?php
	include('connection.php');		
		$adc0 = $_GET['Tempreture'];
		$adc1 = $_GET['Light'];
		$adc2 = $_GET['Moisture'];
		
	$sql = "INSERT INTO data (Tempreture , Light , Moisture) VALUES (:Tempreture , :Light , :Moisture)";
	$stmt =  $PDO->prepare($sql);

	$stmt-> bindParam(':Tempreture',$adc0);
	$stmt-> bindParam(':Light',$adc1);
	$stmt-> bindParam(':Moisture',$adc2);

	
	if($stmt->execute()){
		echo "ok data save";

	}else{
		echo "error saving";
	}
?>





		