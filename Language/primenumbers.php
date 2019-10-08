<!DOCTYPE html>
<html lang="es">
    <head>
        <title>Prime Numbers</title>
        <style>
            h1{
                text-align:center;
            }
            .yes{
                background-color: green;
            }
            .no{
                background-color: red;
            }
        </style>
    </head>
    <body>
        <?php
            function isprimo($n){
                for($x=2; $x<$n; $x++)
                {
                    if($n %$x ==0){
                      return 0;
                    }
                }
                return 1;
            }
            $rand = rand(1,1000);
            $resultado = isprimo($rand);
            if($resultado==0){
                echo "<h1 class=\"no\">$rand is not a prime number.</h1>";
            }else{
                echo "<h1 class=\"yes\">$rand is a prime number.</h1>";
            }
        ?>
    </body>
</html>
