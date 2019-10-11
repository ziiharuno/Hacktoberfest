<?php
$numerosarray = array(7, 4, 100, -45, 0, -9999, 254);
echo "<p>Unordered numbers : " . implode(', ',$numerosarray ) . "</p><br>";
$cantidadarray = count($numerosarray);
for($i=0;$i<=$cantidadarray;$i++)
  {
	for($j=$i+1;$j<=$cantidadarray;$j++)
       {
        if($numerosarray[$j] < $numerosarray[$i])
        {
            $min = $numerosarray[$j];
            $numerosarray[$j] = $numerosarray[$i];
            $numerosarray[$i] = $min;
        }    
       }      
  }
$prueba = "<p>Sorted numbers: " . implode(', ',($numerosarray)) . "</p>";
echo preg_replace("/,/"," ",$prueba,1);
?>
