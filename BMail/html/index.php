<?php
include '../class/Parser.php';
include '../class/imapClass.php';
$parser = new Parser();
$mail = new imapClass($parser->getServer(), $parser->getUser(), $parser->getPassword());


$unread = $mail->totalUnread();
$total = $mail->totalMessages();
$unreadMess = array_reverse($mail->getUnreadMessages());
$mess = array_reverse($mail->getMessage(1, $total));

if (isset($_GET['mail']))
    $emails = $mail->readMessage($_GET['mail']);
if (isset($_GET['delete']))
   $mail->deleteMessage($_GET['delete']);
?>

<!doctype html>
<html lang="en">
<head>
    <meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta name="description" content="A layout example that shows off a responsive email layout.">

    <title>BMail - Nicolas Charvoz &amp; Antoine Garcia</title>

    


<link rel="stylesheet" href="http://yui.yahooapis.com/pure/0.6.0/pure-min.css">







  
    <!--[if lte IE 8]>
        <link rel="stylesheet" href="css/layouts/email-old-ie.css">
    <![endif]-->
    <!--[if gt IE 8]><!-->
        <link rel="stylesheet" href="css/layouts/email.css">
    <!--<![endif]-->
  


    

    

</head>
<body>






<div id="layout" class="content pure-g">
    <div id="nav" class="pure-u">
        <a href="#" class="nav-menu-button">Menu</a>

        <div class="nav-inner">
            <button class="primary-button pure-button">Compose</button>

            <div class="pure-menu">
                <ul class="pure-menu-list">
                    <li class="pure-menu-item"><a href="#" class="pure-menu-link">Inbox <span class="email-count">(<?php echo $unread."/".$total; ?>)</a></li>
                    <li class="pure-menu-item"><a href="#" class="pure-menu-link">Important</a></li>
                    <li class="pure-menu-item"><a href="#" class="pure-menu-link">Sent</a></li>
                    <li class="pure-menu-item"><a href="#" class="pure-menu-link">Drafts</a></li>
                    <li class="pure-menu-item"><a href="#" class="pure-menu-link">Trash</a></li>
                    <li class="pure-menu-heading">Labels</li>
                    <li class="pure-menu-item"><a href="#" class="pure-menu-link"><span class="email-label-personal"></span>Personal</a></li>
                    <li class="pure-menu-item"><a href="#" class="pure-menu-link"><span class="email-label-work"></span>Work</a></li>
                    <li class="pure-menu-item"><a href="#" class="pure-menu-link"><span class="email-label-travel"></span>Travel</a></li>
                </ul>
            </div>
        </div>
    </div>

    <div id="list" class="pure-u-1">

        <?php 

        for ($i = 0; $i < $unread ; $i++)
        {
            echo '<div class="email-item email-item-unread pure-g">
                <div class="pure-u">
                    <img class="email-avatar" alt="Tilo Mitra&#x27;s avatar" height="64" width="64" src="img/common/tilo-avatar.png">
                </div>

                <div class="pure-u-3-4">
                    <h5 class="email-name">'.imap_utf8($unreadMess[$i]['from']) .'</h5>
                    <a href="?mail='.$unreadMess[$i]["msgno"].'"><h4 class="email-subject">'. imap_utf8($unreadMess[$i]['subject']) .'</h4></a>
                    <p class="email-desc"></p>
                </div>
            </div>';
        }
        for ($i = $unread ; $i < $total - $unread ; $i++)
        {
            echo '<div class="email-item pure-g">
                <div class="pure-u">
                    <img class="email-avatar" alt="Tilo Mitra&#x27;s avatar" height="64" width="64" src="img/common/tilo-avatar.png">
                </div>

                <div class="pure-u-3-4">
                    <h5 class="email-name">'.imap_utf8($mess[$i]['from']) .'</h5>
                    <a href="?mail='.$mess[$i]["msgno"].'"><h4 class="email-subject">'. imap_utf8($mess[$i]['subject']) .'</h4></a>
                    <p class="email-desc"></p>
                </div>
            </div>';
        }

        ?>
    </div>

    <div id="main" class="pure-u-1">
        <div class="email-content">
            <div class="email-content-header pure-g">
                <div class="pure-u-1-2">
                    <h1 class="email-content-title"><?php echo imap_utf8($emails['subject']) ;?></h1>
                    <p class="email-content-subtitle">
                        From <a><?php echo imap_utf8($emails['fromaddress']) ?></a> at <span><?php echo imap_utf8($emails['date']) ?></span>
                    </p>
                </div>

                <div class="email-content-controls pure-u-1-2">
                    <button class="secondary-button pure-button">Reply</button>
                    <button class="secondary-button pure-button">Forward</button>
                    <a id='delete' href=" <?php echo "?delete=". $emails['id']; ?>" ><button class="secondary-button pure-button">Remove</button></a>
                </div>
            </div>

            <div class="email-content-body">
                <p style="color:white;">
                    Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
                </p>
                <?php
                    echo imap_qprint($emails['body']);

                ?>
            </div>
        </div>
    </div>
</div>

<script src="http://yui.yahooapis.com/3.17.2/build/yui/yui-min.js"></script>

<script>
    YUI().use('node-base', 'node-event-delegate', function (Y) {

        var menuButton = Y.one('.nav-menu-button'),
            nav        = Y.one('#nav');

        // Setting the active class name expands the menu vertically on small screens.
        menuButton.on('click', function (e) {
            nav.toggleClass('active');
        });

        // Your application code goes here...

    });
</script>



<script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.4/jquery.min.js"></script>
<script src="notify.js"></script>

<script>

$(document).ready(function() {
    $nb = $('.email-count').html().replace('(', '').replace(')', '');
    $.notify("You have " + $nb + " new messages", "info");
});

</script>








</body>
</html>
