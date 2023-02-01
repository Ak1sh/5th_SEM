## Configuring default route to the Router
<ul>
<li>A toplogy was created using three Router-PT, two Switch-PT and two PC's connected to each switch using copper straight-through connections and serial DCE connections<br>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-4/topology.png"/>
</li>
<li>Default gateways and unique ip addresses were configured for each PC .</li>
<li>IP address was configured for each interface using CLI</li>
<li>Pinging PC2 from PC0 gave destination host unreachable</li>
<li>ip routes for each router was viewed using the command: show ip route</li>
<li>Static ip route was configured for router 1 using CLI commands: ip route destination_network subnet_mask next_hop_address </li>
<li>Default ip route was configured for router 0 and router 2 using CLI commands: ip 0.0.0.0 0.0.0.0 next_hop_address </li>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-4/Router0%20config.png"/>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-4/Router1%20config.png"/>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-4/Router2%20config.png"/>
<br>
<li>Pinging PC3 from PC0 gave the required reply</li>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-4/Ping-Output.png"/>
<br>
<li>Simulated sending of an ICMP packet from PC0 to PC2</li>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-4/Simulation-final.png"/>
<br>
</ul>

### Learning outcomes
<ul>
<li>Creating a topology with multiple routers and switches.</li>
<li>Configuring default gateway and ip address.</li>
<li>Configuring ip address for the interfaces</li>
<li>Pinging gives destination host unreachable if the device networks are not directly connected</li>
<li>Configuring static ip route to a router</li>
<li>Configuring default ip route to a router ensures that the packet passes through the default route when no other route is available for an IP destination address</li>
<li>On configuring the default ip routes, pinging gives the required response</li>
<li>The simulation of sending a simple PDU from source to destination shows the route taken by the ICMP packet</li>
</ul>
