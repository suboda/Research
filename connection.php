<?php
//tis is canexao.php
	try {

		$HOST = "localhost";
		$DATABASE = "suboda";
		$USUARIO = "root";
		$SENHA ="";

		$PDO = new PDO("mysql:host=" . $HOST . ";dbname=" . $DATABASE .";charset=utf8", $USUARIO, $SENHA);

	}catch(PDOException $erro){

	//echo "string";		 
	 echo "connection erro";
		}
?>
