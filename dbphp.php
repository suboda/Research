<?php
//this is dbphp.php
//http://127.0.0.1/IOT/dbphp.php?readingIN=12
// use sdbphp1.php"?readingIN=12" to save data
	include('dbtable.php');

	$readingIN = $_GET['readingIN'];


	$sql = "INSERT INTO dbtable (readingIN) VALUES (:readingIN)";

	$stmt =  $PDO->prepare($sql);

	$stmt-> bindParam(':readingIN',$readingIN);
	

	if($stmt->execute()){
		echo "ok data save";

	}else{
		echo "erro_ao_salvar";
	}
?>