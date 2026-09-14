---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-06-16 14:37::22 PM
tags:
  - React
  - ts
---
# Function Components
These can be written as normal functions that take a `props` argument and return a JSX element. 
- `React.FunctionComponent` (or the shorthand `React.FC`)

## Why `React.FC` is Discouraged

If you look at modern codebases or the official React TypeScript Cheatsheets, you will see developers actively avoiding `React.FC`. Here are the three main reasons why:

#### 1. The "Implicit Children" Issue (The Historical Reason)

Before React 18, `React.FC` automatically added `children` to your component's props, whether you wanted them or not. This meant you could pass children to a component that wasn't designed to render them, and TypeScript wouldn't warn you! _(Note: React 18 finally fixed this, but the damage to `React.FC`'s reputation was already done)._

#### 2. It Breaks Generic Components

If you want to create a reusable component that takes a generic type (like a `<Select<T>>` dropdown that works with any data type), `React.FC` completely breaks. It cannot handle generic type arguments passed down to the component.

#### 3. It's Unnecessarily Verbose

TypeScript is incredibly smart. It can automatically infer that a function returning JSX is a valid React component. Adding `React.FC` is extra typing that doesn't actually provide much value.

### The Modern Solution: Direct Props Typing

The recommended approach today is beautifully simple: **Just write a normal JavaScript function and type the `props` argument directly.**

#### The Old Way (Discouraged)

```tsx
const CanvasComponent: React.FC<CanvasProps> = ({ width = 400, height = 300 }) => {
  return <canvas />;
}
```

#### The Modern Way (Recommended)

You simply move the `<CanvasProps>` type definition to the right side of the equals sign, attaching it directly to the props object.
```tsx
// Using an Arrow Function
const CanvasComponent = ({ width = 400, height = 300 }: CanvasProps) => {
  return <canvas />;
}

// Or using a standard function (often preferred for better stack traces)
export default function CanvasComponent({ width = 400, height = 300 }: CanvasProps) {
  return <canvas />;
}
```

#### Why this is better:

1. **No hidden magic:** It only accepts `children` if you explicitly add `children: React.ReactNode` to your `CanvasProps` interface.
2. **Generics work perfectly:** You can easily write `function MyComponent<T>(props: Props<T>)`.
3. **Cleaner code:** It looks and reads like standard JavaScript.
