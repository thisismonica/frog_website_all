<?php
ob_start();
session_start();

session_regenerate_id();
$_SESSION['user_id'] = 0;
$_SESSION['username'] = "demo";
session_write_close();

header('Location: ../show_example.html');

?>
