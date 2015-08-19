#!/bin/bash
dbus-send --print-reply=literal --session --dest=org.gzen_money.Demo /org/gzen_money/demo org.gzen_money.Demo.Ping string:'213'
