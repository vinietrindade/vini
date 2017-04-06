/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testehashset;

import java.util.HashSet;
import java.util.Iterator;

/**
 *
 * @author victor.etrindade
 */
public class HashSetMain {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        HashSetMain<Integer> itens = new HashSetMain<Integer>();
        
        itens.add(1);
        itens.add(3);
        itens.add(4);
        itens.add(6);
        itens.add(10);
        itens.add(16);
        itens.add(19);
        itens.add(20);
        itens.add(25);
        itens.add(30);
        itens.add(40);
        itens.add(42);
        itens.add(47);
        itens.add(51);
        itens.add(55);
        itens.add(57);
        itens.add(70);
        itens.add(77);
        itens.add(89);
        itens.add(100);
        itens.add(124);
        itens.add(145);
        itens.add(200);
        itens.add(450);
        itens.add(508);
        
        
        Iterator<Integer> i = itens.iterator();
        
        while (i.hasNext()) {
            System.out.println(i.next());;
            
        }
        
    }
    
}
