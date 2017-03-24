/* 

		  15              0    31                                    0
  LOGICAL +----------------+   +-------------------------------------+
  ADDRESS |    SELECTOR    |   |                OFFSET               |
          +---+---------+--+   +-------------------+-----------------+
       +------+         !                          |
       | DESCRIPTOR TABLE                          |
       |  +------------+                           |
       |  |            |                           |
       |  |            |                           |
       |  |            |                           |
       |  |            |                           |
       |  |------------|                           |
       |  |  SEGMENT   | BASE          +---+       |
       +->| DESCRIPTOR |-------------->| + |<------+
          |------------| ADDRESS       +-+-+
          |            |                 |
          +------------+                 |
          								 |
            		  +-----------+-----------+----------+         +---------------+
              		  |    DIR    |   PAGE    |  OFFSET  |         |               |
              		  +-----+-----+-----+-----+-----+----+         |               |
                    		|           |           |              |               |
    		  +-------------+           |           +------------->|    PHYSICAL   |
      		  |                         |                          |    ADDRESS    |
    		  |   PAGE DIRECTORY        |      PAGE TABLE          |               |
    		  |  +---------------+      |   +---------------+      |               |
    		  |  |               |      |   |               |      +---------------+
    		  |  |               |      |   |---------------|              ^
    		  |  |               |      +-->| PG TBL ENTRY  |--------------+
    		  |  |---------------|          |---------------|
    		  +->|   DIR ENTRY   |--+       |               |
    		     |---------------|  |       |               |
    		     |               |  |       |               |
    		     +---------------+  |       +---------------+
    		     ^                  |               ^
    +-------+        |          	|		|
    |  CR3  |--------+			+---------------+
    +-------+                 

*/

#define PDE_SHIFT       22
#define PTE_SHIFT       12

#define PDE(va)         (((u32)(va) >> PDE_SHIFT) & 0x3FF)
#define PTE(va)         (((u32)(va) >> PTE_SHIFT) & 0x3FF)

/* construct a virtual address */
#define PGADDR(d, t, o) ((u32)((d) << PDE_SHIFT | (t) << PTE_SHIFT | (o)))