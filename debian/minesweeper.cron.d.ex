#
# Regular cron jobs for the minesweeper package
#
0 4	* * *	root	[ -x /usr/bin/minesweeper_maintenance ] && /usr/bin/minesweeper_maintenance
