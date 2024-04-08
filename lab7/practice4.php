<?php
if (isset($_POST['submit'])) {
    $number = intval($_POST['number']);

    if ($number > 0) {
        echo "<h2>Multiplication Table for 1 to $number</h2>";
        echo "<table border='1'>";
        for ($i = 0; $i <= $number; $i++) {
            echo "<tr>";
            for ($j = 0; $j <= $number; $j++) {
                if ($i == 0 && $j == 0) {
                    echo "<td></td>";
                } elseif ($i == 0) {
                    echo "<td><b>$j</b></td>";
                } elseif ($j == 0) {
                    echo "<td><b>$i</b></td>";
                } else {
                    $result = $i * $j;
                    echo "<td>$result</td>";
                }
            }
            echo "</tr>";
        }
        echo "</table>";
    } else {
        echo "<p>Please enter a valid positive number.</p>";
    }
}
?>