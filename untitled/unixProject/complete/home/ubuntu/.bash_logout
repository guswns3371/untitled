# ~/.bash_logout: executed by bash(1) when login shell exits.

# when leaving the console cls the screen to increase privacy

if [ "$SHLVL" = 1 ]; then
    [ -x /usr/bin/cls_console ] && /usr/bin/cls_console -q
fi
