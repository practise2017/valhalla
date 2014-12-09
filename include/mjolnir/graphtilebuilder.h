#ifndef VALHALLA_MJOLNIR_GRAPHTILEBUILDER_H_
#define VALHALLA_MJOLNIR_GRAPHTILEBUILDER_H_

#include <fstream>
#include <iostream>

#include "baldr/graphid.h"
#include "baldr/graphtile.h"
#include "mjolnir/graphtileheaderbuilder.h"
#include "mjolnir/nodeinfobuilder.h"
#include "mjolnir/directededgebuilder.h"

namespace valhalla {
namespace mjolnir {

/**
 * Graph information for a tile within the Tiled Hierarchical Graph.
 * @author  David W. Nesbitt
 */
class GraphTileBuilder : public baldr::GraphTile {
 public:
  /**
   * Constructor
   */
  GraphTileBuilder();

  /**
   * Output the tile to file. Stores as binary data.
   * @param  filename  File to store data to.
   */
  bool StoreTileData(const std::string& filename);

  /**
   * Add a node and its outbound edges.
   */
  bool AddNodeAndEdges(const NodeInfoBuilder& node,
            const std::vector<DirectedEdgeBuilder>& directededges);
//             const std::vector<EdgeInfoBuilder>& edges,
//             const std::vector<std::string>& names);


 protected:
   // Header information for the tile
   GraphTileHeaderBuilder header_;

   // List of nodes. This is a fixed size structure so it can be
   // indexed directly.
   std::vector<NodeInfoBuilder> nodes_;

   // List of directed edges. This is a fixed size structure so it can be
   // indexed directly.
   std::vector<DirectedEdgeBuilder> directededges_;

   // List of edge info structures. Since edgeinfo is not fixed size we
   // use offsets in directed edges.
   std::vector<char> edgeinfo_;

   // Names as sets of null-terminated char arrays. Edge info has offsets
   // into this array.
   std::vector<std::string> namelist_;

   // Map of edge IDs vs. offsets

//   unsigned int StoreEdgeInfo(const EdgeInfoBuilder& edge);
};

}
}

#endif  // VALHALLA_MJOLNIR_GRAPHTILEBUILDER_H_

