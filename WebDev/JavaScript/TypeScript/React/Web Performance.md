---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-29 15:30::02 PM
tags:
  - React
---
# Web Performance
## CSR (Client Side Rendering)

![[CSR.png]]

- we will download all the data first before rendering.  

## SSR (Server Side Rendering)
![[SSR.png]]

## SSR with Selective Hydration
```tsx
const LazyDataVisualization: React.FC = {} => {
	return(
		<DataVisualizationErrorBoundary>
			<Suspense fallback={<LazyDataVisualizationSkelton />}>
				<DataVisualization />
			</Suspense>
		</DataVisualizationErrorBoundary>
	);
};

export default LazyDataVisualization;
```

- Load Every Thing, Then Hydrate Everything.

## SSR with Streaming and Selective Hydration
 