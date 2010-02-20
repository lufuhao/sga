//-----------------------------------------------
// Copyright 2009 Wellcome Trust Sanger Institute
// Written by Jared Simpson (js18@sanger.ac.uk)
// Released under the GPL license
//-----------------------------------------------
//
// SGAlgorithms - Collection of algorithms for operating on string graphs
//
#ifndef SGALGORITHMS_H
#define SGALGORITHMS_H

#include "Bigraph.h"
#include "SGUtil.h" 

// Visit each node, writing it to a file as a fasta record
struct SGFastaVisitor
{
	// constructor
	SGFastaVisitor(std::string filename) : m_fileHandle(filename.c_str()) {}
	~SGFastaVisitor() { m_fileHandle.close(); }

	// functions
	void previsit(StringGraph* /*pGraph*/) {}
	bool visit(StringGraph* pGraph, Vertex* pVertex);
	void postvisit(StringGraph* /*pGraph*/) {}

	// data
	std::ofstream m_fileHandle;
};

// Run the Myers transitive reduction algorithm on each node
struct SGTransRedVisitor
{
	SGTransRedVisitor() {}
	void previsit(StringGraph* pGraph);
	bool visit(StringGraph* pGraph, Vertex* pVertex);
	void postvisit(StringGraph*);

	int marked_verts;
	int marked_edges;
};

// Close transitive groups by inferring missing edges
struct SGGroupCloseVisitor
{
	SGGroupCloseVisitor() {}
	void previsit(StringGraph* pGraph);
	bool visit(StringGraph* pGraph, Vertex* pVertex);
	void postvisit(StringGraph*);

	int numGroupsClosed;
	int numGroupsOpen;
	int numEdgesRejected;
};

// Detect whether vertices are dead ends and mark them for removal
struct SGTrimVisitor
{
	SGTrimVisitor() {}
	void previsit(StringGraph* pGraph);
	bool visit(StringGraph* pGraph, Vertex* pVertex);
	void postvisit(StringGraph*);

	int num_island;
	int num_terminal;
	int num_contig;
};

// Detect and remove duplicate edges
struct SGDuplicateVisitor
{
	SGDuplicateVisitor() {}
	void previsit(StringGraph*) {}
	bool visit(StringGraph* pGraph, Vertex* pVertex);
	void postvisit(StringGraph*) {}
};

// Detect small island vertices and removal them
struct SGIslandVisitor
{
	SGIslandVisitor() {}
	void previsit(StringGraph* pGraph);
	bool visit(StringGraph* pGraph, Vertex* pVertex);
	void postvisit(StringGraph*);
};


// Detect whether vertices are bubbles and mark them for removal
struct SGBubbleVisitor
{
	SGBubbleVisitor() {}
	void previsit(StringGraph* pGraph);
	bool visit(StringGraph* pGraph, Vertex* pVertex);
	void postvisit(StringGraph*);
	int num_bubbles;
};

// Perform a transitive closure step
// by inferring missing edges in the graph 
struct SGTCVisitor
{
	SGTCVisitor() {}
	void previsit(StringGraph* pGraph);
	bool visit(StringGraph* pGraph, Vertex* pVertex);
	void postvisit(StringGraph*);

	int ngb;
	int nbb;
};

// Compile summary statistics for the graph
struct SGGraphStatsVisitor
{
	SGGraphStatsVisitor() {}
	void previsit(StringGraph* pGraph);
	bool visit(StringGraph* pGraph, Vertex* pVertex);
	void postvisit(StringGraph*);

	int num_terminal;
	int num_island;
	int num_monobranch;
	int num_dibranch;
	int num_transitive;
	int num_edges;
	int num_vertex;	
};

#endif
